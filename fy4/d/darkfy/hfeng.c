
inherit ROOM;

void create()
{
        set("short", "佻���");
        set("long", @LONG
�����ǽ�ڹ����˷�ɵĻ�����ɢ�������˵����������õ�������һ����ɫ����
����ͭ�ɺף���������Ʈ���������̣�������Ƣ�����õ��ұ���һ��СС�Ĺ�̨��̨
�ӵĺ�����һ��ľ�ܣ������Ϲ����˰�ë��
LONG
        );
        set("exits", ([
                "west" : __DIR__"nwind3",
		"east" : __DIR__"hfenglang1",
        ]));
        set("objects", ([
                __DIR__"npc/": 1,
        ]) );
        set("coor/x",11);
        set("coor/y",30);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);

}
