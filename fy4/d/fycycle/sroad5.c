inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
С�����ŷ��ƳǵĻ��Ǻ�����ȥ���ϱ���һƬ��ľ��������֡������ﴫ��
һ����ı��н�������������ʱ�������ż���ߺ�ȣ�ߺ�ȵ����������㣬һ����֪
�������ָ��֡�·�ϵ�����������ǣ�������Щ���š�
LONG
        );

	set("objects", ([
		"/d/bashan/npc/mazemaster" :1,
	]) );

        set("exits", ([ /* sizeof() == 4 */
		  "northeast" : __DIR__"sroad6",
		  "southwest": __DIR__"sroad4",
		  "southeast": __DIR__"sroad7",
	]));
        set("outdoors", "fengyun");
	set("coor/x",200);
	set("coor/y",-200);
	set("coor/z",0);
	setup();
}

