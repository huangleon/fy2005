inherit __DIR__"no_killing_place";
void create()
{
    set("short", "�ݵ�");
    set("long", @LONG
������һƬ�����ݵأ�������ï�ܵĴ��֡��ݵ��ϵĲ�ϸ��������ϸ���С
�������ڣ�������Ů��ǰ���㷢����Ե�������ֵĵط��м�ֻСè������ˣ��һ
�����ѵ�С·��������������չ�ţ�����������һ�ô��̵�С����
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"walnuttree",
        "west" : __DIR__"forest",
        "north" : __DIR__ "road5",
        ]));
    set("objects", ([
        __DIR__"npc/cat1" :1,
        __DIR__"npc/cat2" :1,
        ]) );

	set("no_lu_letter",1);
    set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",40);
	set("coor/y",-10);
	set("coor/z",0);
    setup();
    replace_program( __DIR__"no_killing_place");

}
