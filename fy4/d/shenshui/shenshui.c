// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ˮ�ܲش�");
        set("long", @LONG
��ˮ������������ˮ���֮�����ഫ��ˮ��ɫ��ζ���ȿ�Ĩ�ڵ���Ҳ��������
ˮ�У��������У�ͷ�����ѣ��������顣��Ϊ���ﶾ�����£������������Լ���
��ˮ���ӣ�Ҳ��������˵أ�ֻ�л�ù�����������ȡ�����Ρ�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"guayu",
]));
	set("coor/x",-700);
	set("coor/y",-12730);
	set("coor/z",60);
	setup();
        replace_program(ROOM);
}
