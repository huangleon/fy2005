inherit __DIR__"no_killing_place";
void create()
{
    set("short", "ʯ��·��ͷ");
    set("long", @LONG
����ʯ��·���������Ѿ���������������ǣ�����ǰ�ƺ�û����·����������
�����ݣ�������ï�ܵĴ��֣��������౵���������������ˮ����͸����ǰ�Ĵ�
������������Կ���һƬ����ɫ�Ĳݵء�
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"riverbank",
        "west" : __DIR__"road4",
        "south" : __DIR__ "lawn",
        ]));
	set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",40);
	set("coor/y",0);
	set("coor/z",0);
    setup();
        replace_program( __DIR__"no_killing_place");
}
