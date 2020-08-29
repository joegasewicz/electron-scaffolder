import * as React from "react";
import * as ReactDOM from "react-dom"

import "./sass/index.scss";
import {Main} from "./views/main";
import {GlobalStyle} from "./views/main.styles";

function App() {
  return (
    <>
      <GlobalStyle />
      <Main />
    </>
  );
}

ReactDOM.render(
  <App />,
  document.getElementById("app")  
);
