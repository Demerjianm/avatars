import 'normalize.css'
import './layout.css'
import './fonts.css'
import './text.css'
import React from 'react'
import PropTypes from 'prop-types'
import Helmet from 'react-helmet'
import { StaticQuery, graphql } from 'gatsby'

const Layout = ({ children }) => (
  <StaticQuery
    query={graphql`
      query SiteTitleQuery {
        site {
          siteMetadata {
            title
          }
        }
      }
    `}
    render={() => <>{children}</>}
  />
)

Layout.propTypes = {
  children: PropTypes.node.isRequired,
}

export default Layout
