// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ؽ�¥");
        set("long", @LONG
����ܿտ��������ڴ˲��ɸе�������Щ���ѣ��������������������ܣ�����
�ָ�����˸����������е����������е��Ѫ����ÿ�������Ϸ�����һ����������
��ɢ������ɱ����ɱ�����˱���ѹ����
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"huayuan",
]));
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
