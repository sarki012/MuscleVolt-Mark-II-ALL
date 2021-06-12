package com.esark.musclevolt_mark_v;

import android.content.Context;
import android.content.Intent;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import android.os.Bundle;
import android.os.Parcelable;

import com.esark.framework.Game;
import com.esark.framework.Graphics;
import com.esark.framework.Input.TouchEvent;
import com.esark.framework.Screen;

import java.util.List;

public class GameScreen extends Screen{
    Context context = null;
    int xStart = 0, xStop = 0;
    public static int [] A2DVal = new int[300];
    String percent = "22%";


    //Constructor
    public GameScreen(Game game) {
        super(game);
    }
    @Override
    public void update(float deltaTime, Context context) {
        //framework.input
        List<TouchEvent> touchEvents = game.getInput().getTouchEvents();
        updateRunning(touchEvents, deltaTime, context);
    }
    private void updateRunning(List<TouchEvent> touchEvents, float deltaTime, Context context) {
        //updateRunning() contains controller code of our MVC scheme
        Graphics g = game.getGraphics();
        int len = touchEvents.size();
        //Check to see if paused
        for (int i = 0; i < len; i++) {
            TouchEvent event = touchEvents.get(i);
            if (event.type == TouchEvent.TOUCH_UP) {
                if (event.x < 100 && event.y > 430) {
                    //Back Button Code Here
                  //  Intent intent2 = new Intent(context.getApplicationContext(), MainActivity.class);
              //      intent2.putExtra("Game", game);
               //     context.startActivity(intent2);

                  //  MainActivity.openActivity(context.getApplicationContext(), game);

                    /*
                    Intent intent3 = new Intent();
                    Bundle b = new Bundle();
                    b.putParcelable("Game", game);
                    intent3.putExtras(b);
                    intent3.setClass(context.getApplicationContext(), MainActivity.class);
                    context.startActivity(intent3);

                     */
                    return;
                }
                else if (event.x > 150 && event.y > 430) {
                    //Back Button Code Here
                    game.setScreen(new BarGraph(game));
                    // Intent intent3 = new Intent(context.getApplicationContext(), Results.class);
                    //context.startActivity(intent3);
                    return;
                }
            }
        }
        //////////Write UI Code Here. He have a background, Pixmap, and Line ready to use//////////////////
        /////////Make a moving sine wave here/////////////////////////////////////////////////////////////
        //g.clear(0xff0000);
        g.drawPixmap(Assets.background, 0, 0);
        g.drawPixmap(Assets.backArrow, 5, 430);
        //Pixmap Button to take us to the Results screen
        g.drawPixmap(Assets.results, 125, 430);

        xStart = 0;
        xStop = 1;

        for(int m = 1; m < 300; m++) {
            g.drawLine(xStart, A2DVal[m - 1], xStop, A2DVal[m], 0);
            xStart = xStop;
            xStop++;
        }

        g.drawText(percent, 100, 75);



        //    g.drawLine(10,10,700, 900, 0);
    }

    @Override
    public void present(float deltaTime) {
        Graphics g = game.getGraphics();
    }

    @Override
    public void pause() {

    }

    @Override
    public void resume() {

    }

    @Override
    public void dispose() {

    }
}
