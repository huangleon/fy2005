inherit ROOM;

void create()
{
        set("short", "ç�ֱ�Ե");
        set("long", @LONG
������Ķ�����һƬç�֣�Խ������Խ�ܣ�������������������Ҳ��ð߰ߵ�
�㡣é�ݽ��񣬹�ľ�����������ķ�ҲԽ�������䳱ʪ��Զ�����ֵ�������м�ֻ
������ͺӥ������˺���ѷεĽ���������ë����Ȼ���ֱ�����ŤŤ�ع����Ÿ�ʾ��
		[33m����ç�֣����޳�û������Ī�롻[32m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"groupw1",
  		"west" : AREA_CHENXIANG"cxe3",
	]));
        set("outdoors", "manglin");
	set("NONPC",1);
	set("coor/x",-410);
	set("coor/y",-100);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
