// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�޺���");
        set("long", @LONG
�����������µ��޺��ã�����ǽ����ʮ���޺����˸��죬�϶�Ϊ�޺�ʮ���֡�
���ܽ����޺��õĵ��ӣ��书��Ϊһʱ֮ѡ��������סɮ��Ժ��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"jialan",
  "east" : __DIR__"bingeast",
  "west" : __DIR__"bingwest",
  "north" : __DIR__"damo",
]));
        set("objects", ([
                __DIR__"npc/master_19" : 1,
       ]) );
	set("coor/x",0);
	set("coor/y",80);
	set("coor/z",20);
	setup();

}
