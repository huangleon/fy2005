
inherit ROOM;

void create()
{
    set("short", "��ͻȪ");
	set("long", @LONG
��ͻȪ�ųơ����µ�һȪ������Ѱ��Ȫˮ֮������Ȼ��ͬ��ʢˮ���ڣ����һ
�����ϣ�׳�����Ѱ�ѩ����ʫ���ƣ����߲���ƽ��ѩ����ʱ��������ס�Ȫˮ�Ʊ�
��һ������Ө���ȽȽ�ϸ���ˮ�ݣ�ϸ�����ۣ��������ơ���Ԩ��Ȫ��������
ƽ���ͣ���Ȼ����һ�ָ���͵�ð����е������Ȫ�ߴ��˼���ͤ��һ��������Ů��
���С��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"street4",
]));
        set("objects", ([
        __DIR__"npc/songtian" : 1,
                        ]) );
        set("resource/water",1);
        set("liquid", ([
        "container":"��ͻȪ",
        "name":		"��ͻȪˮ",
        	]));
        	
    set("outdoors", "jinan");
	set("coor/x",10);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}

//void init()
//{
//    add_action("do_swim", "swim");
//}
//
//int do_swim(string arg)
//{
//   return 1;
//}
