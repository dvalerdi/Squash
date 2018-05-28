#include "screencasts.h"

int main(int argc, char* argv[])
{
	if (!initKinect()) return 1;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow(windowName);

	glutDisplayFunc(display);
	glutReshapeFunc(displayReshape);
	glutKeyboardFunc(windowKey);
	glutSpecialFunc(windowSpecial);
	glutPassiveMotionFunc(mouseCallback);
	glewInit();

	glutCreateMenu(windowMenu);
	glutAddMenuEntry("Toggle Axes [1]", '1');
	glutAddMenuEntry("Toggle Values [2]", '2');
	glutAddMenuEntry("Toggle Mode [3]", '3');
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//glutMouseFunc(windowMouse);
	//glutPassiveMotionFunc(windowPmotion);
	
	glutTimerFunc(ms, stepBall, 50);
	redisplayAll();
	glutMainLoop();
	/*Timer for animation*/
	
	return 0;
}