inherit __DIR__"no_killing_place";
void create()
{
    set("short", "����ʯ��·");
    set("long", @LONG
����ʯ��·���ѵش������д����������ʯ�屻ɽ�ּ�ı������ʪ������
���͵����Ź⣻ʯ������̦���ܵ������˷�϶�������������·��������������
Ь���Ž�Ѿ���������ܣ����һ���������е�������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"road3",
        "east" : __DIR__"road5",
        ]));
	set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
    setup();
        replace_program( __DIR__"no_killing_place");
}


