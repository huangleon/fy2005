
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�˶�ߣ�ֻ�����˲��е�̴��ľ���ȣ����е����������һЩ�滨��ݡ�����
���������ȵ�һͷð������̴ľ�ذ�����ʪ�ֻ����㼸��Ҫ�������˲Ų��Ử����
LONG
        );
        set("exits", ([
                "south" : __DIR__"jlonglang1",
		"west" : __DIR__"jlonglang3",
        ]));
        set("coor/x",-20);
        set("coor/y",40);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);

}
