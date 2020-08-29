import * as React from "react";
import { useState } from "react";
import {Form, isFieldEmpty,FormConsumer, SubmitButton, TextInputField, PasswordField} from "react-bare-forms";

import {Wrapper} from "./main.styles";



export function Main() {
    const formState = {
        email: "test1",
        password: "test2",
    };
    const [state, setState] = useState(formState);
    return (
    <Wrapper>
        <div className="container">
            <h1 className="text-center">Sign Up</h1>
            <div className="row">
                <div className="col-md-2"></div>
                <div className="col-md-8">
                    <Form
                        context={setState}
                        state={state}
                        callback={() => console.log("Form submitted ----> ")}>
                        <TextInputField
                            autoFocus={true}
                            value={state.email}
                            name="email"
                        />
                        <PasswordField
                            autoFocus={true}
                            value={state.password}
                            name="password"
                        />
                        <SubmitButton>Submit</SubmitButton>

                        <FormConsumer>
                            {(context: any) => {
                                return <code>{JSON.stringify(context.metadata)}</code>;
                            }}
                        </FormConsumer>
                    </Form>
                </div>
                <div className="col-md-2"></div>
            </div>
        </div>
    </Wrapper>);
};
