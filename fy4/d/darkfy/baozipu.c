
inherit ROOM;

void create()
{
        set("short", "Ѧ�ǰ���");
        set("long", @LONG
���ﲼ�ü�ª��ֻ�м��ŷ����ͼ��ų��ʡ�����������䣬��Ҳ��������ԭ������
ɫ����������Ƶ�������ҵ�ɢ���������ϡ�ǽ���ﻹ�м�֧��ϡϡ�Ŀ��ӣ������ѽ�
����֩��������ֻ��Ӭ��äĿ�ķ�����ȥ������
LONG
        );
        set("exits", ([
		"east" : __DIR__"nwind5",
        ]));
        set("objects", ([
                __DIR__"npc/": 1,
        ]) );
        set("coor/x",-10);
        set("coor/y",50);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);

}
