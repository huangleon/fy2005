inherit __DIR__"no_killing_place";
void create()
{
    set("short", "����ʯ��·");
    set("long", @LONG
����ʯ��·��ɽ�ּ�ı������ʪ���������͵����Ź⣻ʯ������̦����
�������˷�϶��ʯ��·�ı�����һ��СС��Ժ�䣬ԭľΧ������������������٣�
�������ǵ�׺�ż����ɫ�Ļ���
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"anju",
        "west" : __DIR__"road2",
        "east" : __DIR__"road4",
        ]));
	set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
    setup();
        replace_program( __DIR__"no_killing_place");
}
