// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ժ");
        set("long", @LONG
���������������������⣬������λ���³��ϣ��书������ߣ��ҷ𷨾��
�ĳ���ִ��ɮ�࣬ά�����ְ�ȫ�����������ֲ��ڷ���֮�£��ߴ���������λ����
������ǧ�������ɫ����λ������ʮ�������������ӳ�����ɮ�ࡣ
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"jian",
  "southeast" : __DIR__"laoe",
  "southwest": __DIR__"lao",
]));
        set("objects", ([
                __DIR__"npc/master_17_4" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",130);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
