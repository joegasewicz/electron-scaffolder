import * as React from "react";
import { useState } from "react";
import {Form, FormConsumer, SubmitButton, TextInputField, PasswordField, isFieldEmpty,areFieldsEqual} from "react-bare-forms";

import {Wrapper} from "./main.styles";



export function Main() {
    const formState = {
        email: "",
        password: "",
        confirmPassword: "",
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
                        callback={() => console.log("Form submitted")}>
                        <TextInputField
                            value={state.email}
                            name="email"
                            hint="Enter your email"
                            labelText="Email"
                            validators={[isFieldEmpty(2)]} />

                        <PasswordField
                            name="password"
                            value={state.password}
                            hint="Needs to be at least 2 characters long"
                            labelText="Password"
                            validators={[isFieldEmpty(2)]}
                        />

                        <PasswordField
                        value={state.confirmPassword}
                        name="confirmPassword"
                        hint="Must be equal to password"
                        labelText="Confirm password"
                        validators={[isFieldEmpty(2), areFieldsEqual("password")]}
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
