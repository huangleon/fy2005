// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�鷿");
        set("long", @LONG
һ�ź�ľ�����������У�ǽ�����֮�ϣ�������Ӱټ�����ѧ�伮��ǽ�ڶ���
���黭��������������һ����ɫ�����С�������治֪��ȼ����ʲô������������
����һ�㵭��ɫ�����������š�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"huayuan",
]));
   set("objects", ([
      __DIR__"npc/swordmaster": 1,
   ]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
