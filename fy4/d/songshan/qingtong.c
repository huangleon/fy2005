// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ͯ��");
        set("long", @LONG
̫�Ҷ��ĸ߷壬�վ�ȴ�Դ䣬����¬���ٲ���������¼���СС���������
�����վ�����ƫƧ����������Ҳ��̫�࣬���������ʿ����ȴ�మ�ڴ˳�����ɽ��
ˮ�������𣬵�������ѧ��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"luya", 
]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"npc/shuzhen" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",14);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
