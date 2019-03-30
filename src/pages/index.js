import React from 'react'
import { Link, graphql, navigate, withPrefix } from 'gatsby'
import html2canvas from 'html2canvas'

import App from '../../re/App.bs'
import Layout from '../components/layout'
import AWS from 'aws-sdk'
import { x, y, z } from '../config.js'
const s3 = new AWS.S3()
s3.config.update({
  region: 'us-west-2',
  credentials: {
    accessKeyId: x,
    secretAccessKey: y,
  },
})
console.log(s3)
function getRandom(list) {
  const l = list.length
  return list[Math.floor(Math.random() * l)]
}

function randomizeStyles(config) {
  return {
    skin: 'Skin',
    skinColor: getRandom(config.skinColors),
    hairColor: getRandom(config.hairColors),
    hair: getRandom(config.hairStyles),
    facialHair: getRandom(config.facialHairStyles),
    facialHairColor: getRandom(config.facialHairColors),
    body: getRandom(config.bodyStyles),
    bodyColor: getRandom(config.bodyColors),
    eyes: getRandom(config.eyeStyles),
    mouth: getRandom(config.mouthStyles),
    nose: getRandom(config.noseStyles),
    bgColor: getRandom(config.bgColors),
  }
}
const DEFAULT_STYLES = {
  skin: 'Skin',
  skinColor: 'B16A5B',
  hairColor: 'E16381',
  hair: 'Balding',
  facialHair: 'Mustache',
  facialHairColor: '6C4545',
  body: 'Square',
  bodyColor: '5A45FF',
  eyes: 'Glasses',
  mouth: 'Pacifier',
  nose: 'Smallround',
  bgColor: 'FFCC65',
}

export default class IndexPage extends React.PureComponent {
  constructor(props) {
    super(props)
    const config = this.props.data.allDataJson.edges[0].node

    this.state = {
      styles: DEFAULT_STYLES,
      showModal: false,
    }
  }

  componentDidMount() {
    this.getParameterByName('id', 'id')
  }

  _onChange = (key, value) => {
    const change = { [key]: value }
    this.setState({
      styles: {
        ...this.state.styles,
        ...change,
      },
    })
  }

  getParameterByName(name, field) {
    var url = window.location.href
    name = name.replace(/[\[\]]/g, '\\$&')
    var regex = new RegExp('[?&]' + name + '(=([^&#]*)|&|#|$)'),
      results = regex.exec(url)
    if (!results) {
      return
      throw Error(
        'Looks like something went wrong please try the link again or contact support. Sorry!'
      )
      alert(
        'Looks like something went wrong please try the link again or contact support. Sorry!'
      )
    }
    var id = decodeURIComponent(results[2].replace(/\+/g, ' '))
    if (id) this.setState({ [field]: id })
  }

  _randomize = () => {
    const config = this.props.data.allDataJson.edges[0].node
    const styles = randomizeStyles(config)
    this.setState({ styles })
  }

  s3upload = async file => {
    // try {
    const filename = `${this.state.id}`
    const img = await this.srcToFile(file, filename, 'image/png')
    //   console.log(img)
    //   const stored = await Storage.put(filename, img, {
    //     contentType: img.type,
    //   })
    //   console.log(stored)
    //   return stored.key
    // } catch (e) {
    //   console.log('s3 upload error: ', e)
    // }
    var params = {
      Body: img,
      Bucket: z,
      Key: filename,
    }
    s3.putObject(params, function(err, data) {
      if (err) console.log(err, err.stack)
      // an error occurred
      else console.log(data) // successful response
    })
  }

  srcToFile = async (src, fileName, mimeType) => {
    return fetch(src)
      .then(function(res) {
        return res.arrayBuffer()
      })
      .then(function(buf) {
        return new File([buf], fileName, { type: mimeType })
      })
  }

  _exportImage = async () => {
    this.setState({ showModal: true })
    const node = document.getElementsByClassName(
      'AvatarGenerator-pngContainer'
    )[0]
    console.log(Storage)

    const canvas = await html2canvas(node)
    const dataUrl = canvas.toDataURL()
    const link = document.createElement('a')
    link.download = 'avatar.png'
    link.href = dataUrl
    document.body.appendChild(link)

    await this.s3upload(dataUrl)
  }

  render() {
    const { styles, showModal } = this.state
    const config = this.props.data.allDataJson.edges[0].node
    console.log('this state: ', this.state)
    return (
      <Layout>
        <App
          onToggleModal={() => this.setState({ showModal: false })}
          showModal={showModal}
          {...config}
          {...styles}
          onChange={this._onChange}
          onExport={this._exportImage}
          randomize={this._randomize}
        />
      </Layout>
    )
  }
}

export const query = graphql`
  query ConfigQuery {
    allDataJson {
      edges {
        node {
          skinStyles
          hairStyles
          facialHairStyles
          bodyStyles
          eyeStyles
          mouthStyles
          noseStyles
          bgStyles
          skinColors
          hairColors
          facialHairColors
          bodyColors
          bgColors
          disabledColors
        }
      }
    }
  }
`
