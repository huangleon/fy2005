// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ۡ԰����");
        set("long", @LONG
ۡ԰���������þ޸��Իƽ��̵أ������������˵���Ļ�԰���ɼ��侫���ͱ�
�������ۡ԰��������ۡ԰����ֻ��Ҳ���ض��ã�ҡҷ����Ӱ���ų����з�ɫ��
˯����ǳ���Ļ�ݺ��������ǰ�Ĳ�ϼ��һ��̴�����ζ����������һƬ�徲������
���ܣ��ϱ�����һС¥��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"shan",
  "west" : __DIR__"zhulin",
  "north" : __DIR__"qingjing",
  "south" : __DIR__"wuwei",
]));
        set("objects", ([
                __DIR__"npc/zauron" : 1,
       ]) );
	set("coor/x",-20);
	set("coor/y",120);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
