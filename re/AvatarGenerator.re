open Belt;

[%bs.raw {|require('./AvatarGenerator.css')|}];

type _settings = {
  id: string,
  label: string,
  colors: list(string),
  styles: list(string),
  selectedColor: string,
  selectedStyle: string,
};

let getZIndex = id =>
  switch (id) {
  | "Eyes" => "110"
  | "Nose" => "100"
  | "FacialHair" => "90"
  | "Mouth" => "80"
  | "Body" => "75"
  | "Hair" => "70"
  | "Head" => "40"
  | "Skin" => "30"
  | "Background" => "20"
  | _ => "10"
  };

type state = {rotation: int};

type action =
  | Randomize;

let component = ReasonReact.reducerComponent("AvatarGenerator");
let make = (~randomize, ~settings, ~onChange, ~onExport, _children) => {
  ...component,
  initialState: () => {rotation: 0},
  reducer: (action, state) =>
    switch (action) {
    | Randomize =>
      ReasonReact.UpdateWithSideEffects({rotation: state.rotation + 1}, _self => {
        randomize();
      })
    },
  render: ({state, send}) => {
    let rotation = "rotate(" ++ string_of_int(state.rotation * 50) ++ "deg)";
    let pngImage =
      List.map(settings, o =>
        <SvgLoader
          key=o.id
          style={ReactDOMRe.Style.make(~zIndex=getZIndex(o.id), ())}
          className="AvatarGenerator-png"
          name={o.selectedStyle}
          fill={"#" ++ o.selectedColor}
          size="512"
        />
      );

    let faceFeatures =
    List.map(settings, o =>
      <SvgLoader
        key=o.id
        style={ReactDOMRe.Style.make(~zIndex=getZIndex(o.id), ())}
        className="AvatarGenerator-faceFeature"
        name={o.selectedStyle}
        fill={"#" ++ o.selectedColor}
        size="150"
      />
    );

    let styleOptions =
      List.map(settings, o =>
        <Styler
          key=o.id
          id={o.id}
          label={o.label}
          colors={o.colors}
          styles={o.styles}
          selectedColor={o.selectedColor}
          selectedStyle={o.selectedStyle}
          onSelectColor={
            color => {
              let key =
                switch (o.id) {
                | "Skin" => "skinColor"
                | "Hair" => "hairColor"
                | "FacialHair" => "facialHairColor"
                | "Body" => "bodyColor"
                | "Background" => "bgColor"
                | _ => ""
                };

              onChange(key, color);
            }
          }
          onSelectStyle={style => {
            let key = switch(o.id) {
              | "Hair" => "hair"
              | "Skin" => "skin"
              | "FacialHair" => "facialHair"
              | "Body" => "body"
              | "Eyes" => "eyes"
              | "Mouth" => "mouth"
              | "Nose" => "nose"
              | _ => ""
            }
            onChange(key, style);
          }}
        />
      );
    <div className="AvatarGenerator-container">
      <div className="AvatarGenerator-pngContainer">
        {ReasonReact.array(List.toArray(pngImage))}
      </div>
      <div className="AvatarGenerator-avatar">
        {ReasonReact.array(List.toArray(faceFeatures))}
      </div>
      <button className="Text-link" onClick={_ => send(Randomize)}>
        {ReasonReact.string("Randomize")}
        <Icon
          name="randomize"
          style={ReactDOMRe.Style.make(~transform=rotation, ())}
        />
      </button>
      <div className="AvatarGenerator-row">
        {ReasonReact.array(List.toArray(styleOptions))}
      </div>
      <button onClick={_ => onExport()} className="Button-primary Text-button">
        {ReasonReact.string("Download Avatar")}
      </button>
      <div className="AvatarGenerator-footer">
       
      </div>
    </div>;
  },
};
