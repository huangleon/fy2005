// inn.c

inherit ROOM;


void create()
{
    set("short", "�Ϲ�Ǯׯ");
    set("long", @LONG
��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����˼�Ǯׯ���Һ��֣������Ϲ���ҵ֮
һ���Ϲ�Ǯׯ����Ʊ�������ã����ϱ����ɶ��֡����Ǹ��ɵй��Ľ�Ǯ�Ҳ����
�����Ǯׯ������һ��ľ��̨�����˶�ߣ������ƣ�����һ�顣
[31m
                	�Ϲ�Ǯׯ
[32m
LONG
    );

    set("exits", ([
	"west"      : __DIR__"nstreet1",
      ]) );
    set("item_desc", ([
	"sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ��
withdraw    ��ȡ���
deposit     ����Ǯ��
balance     ��ѯ�������
loan	    ��Ǯׯ��Ǯ
transfer    ֱ��ת��

TEXT
      ]) );


    set("objects", ([
	__DIR__"npc/bankowner" : 1,

      ]) );

    set("coor/x",0);
    set("coor/y",10);
    set("coor/z",0);
    set("map","biancheng");
    setup();
}
