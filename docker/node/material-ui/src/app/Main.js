/**
 * In this file, we create a React component
 * which incorporates components providedby material-ui.
 */
import React, {Component} from 'react';
import RaisedButton from 'material-ui/RaisedButton';
import Dialog from 'material-ui/Dialog';
import {deepOrange500} from 'material-ui/styles/colors';
import FlatButton from 'material-ui/FlatButton';
import getMuiTheme from 'material-ui/styles/getMuiTheme';
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';
import http from 'http';

const styles = {
  container: {
    textAlign: 'center',
    paddingTop: '15%',
  },
  button: {
    margin: 6,
  },
};

const muiTheme = getMuiTheme({
  palette: {
    accent1Color: deepOrange500,
  },
});

class Main extends Component {
  constructor(props, context) {
    super(props, context);

    this.handleRequestClose = this.handleRequestClose.bind(this);
    this.handleTouchTap = this.handleTouchTap.bind(this);

    this.state = {
      open: false,
    };
  }

  handleRequestClose() {
    this.setState({
      open: false,
    });
  }

  handleTouchTapFire() {
    location.href = '/red';
  }

  handleTouchTap() {
    this.setState({
      open: true,
    });
  }

  render() {
    const standardActions = (
      <div>
        <RaisedButton label="Think Over" primary={true} style={styles.button} onTouchTap={this.handleRequestClose} />
        <FlatButton label="OK, Fire" secondary={true} style={styles.button} onTouchTap={this.handleTouchTapFire} />
      </div>
    );

    return (
      <MuiThemeProvider muiTheme={muiTheme}>
        <div style={styles.container}>
          <Dialog
            open={this.state.open}
            title="Super Secret World"
            actions={standardActions}
            onRequestClose={this.handleRequestClose}
          >
            Are you sure ready to take the adventure?
          </Dialog>
          <h1>Material-UI</h1>
          <h2>the cloud of REDs</h2>
          <RaisedButton
            label="Super Secret World"
            secondary={true}
            onTouchTap={this.handleTouchTap}
          />
        </div>
      </MuiThemeProvider>
    );
  }
}

export default Main;
