inherit ROOM;

void create()
{
	set("short", "�Ͼ����");

	set("long", @LONG
���Խ��Խխ������ת�䣬��ת��һ����·��������һ·�ķ��Ҳ��Ȼһ�䣬
���ܲ�ľ������Σ������ƽ����㲻���������˿�������ĿԶ����Զ������������
�����Ǹ����� 
LONG);

	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"south":__DIR__"yidao4",
		"northeast":__DIR__"qinshilu4",
	]) );
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
