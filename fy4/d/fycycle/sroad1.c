inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
һ��С·���������������졣·���Ա��Ƿ��ƳǵĻ��Ǻӣ��ӵ�����һ�߾���
�ߴ�ķ��Ƴǳ�ǽ�ˡ���������Կ�����ǽ��ֵ�ڵ�ʿ����վ�ڡ��ӵ��ϳ�������
�ݡ�΢�������һ�������ķ��㡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "north" :__DIR__"fywest",
		  "southeast" : __DIR__"sroad2",
	]));
        set("outdoors", "fengyun");
	    
	set("coor/x",-320);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
}

