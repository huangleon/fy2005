
inherit ROOM;

void create()
{
        set("short", "Ʈ�㻨��");
        set("long", @LONG
δ��˴������µĻ������������ԡ����и���������������Ŀ�������������֡�
���Ͳ��ָߵ͹�����������������Ц����ӭ�������е������˶�ϲ�������������
����һ���һ��˻ή���������ϡ���������ϰ�˵����Ʈ�㻨���ɵ���Ե�Ѳ���ʤ
����
LONG
        );
        set("exits", ([
		"west" : __DIR__"nwind2",
        ]));
        set("objects", ([
                __DIR__"npc/flowerseller": 1,
		__DIR__"npc/youngman": 2,
        ]) );
        set("coor/x",1);
        set("coor/y",20);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);

}
