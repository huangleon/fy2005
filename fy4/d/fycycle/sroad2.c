inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
һ��С·���������������졣·���Ա��Ƿ��ƳǵĻ��Ǻӣ��ӵ�����һ�߾���
�ߴ�ķ��Ƴǳ�ǽ�ˡ���������Կ�����ǽ��ֵ�ڵ�ʿ����վ�ڡ��ӵ��ϳ�������
�ݡ�΢�������һ�ɵ������ķ��㡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"sroad1",
  "southeast": __DIR__"sroad3",
]));
        set("outdoors", "fengyun");
         

	set("coor/x",-200);
	set("coor/y",-200);
	set("coor/z",0);
	setup();
}

