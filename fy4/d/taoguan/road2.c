
inherit ROOM;

void create()
{
	set("short", "ʯӢ��ʯ��");
	set("long", @LONG
վ������ݵ����, ����ɫ����ʯӢ�����Ѷ���, ������ɽɫ�з·�һ��
����ɫ�ľ�����̧ͷ����ɽ�������������, ��Ȼ����������Ѿ�������������
�ۼ�, ���Բ�ʧ��ׯ����ʥ������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"west" : __DIR__"putian",
  		"northup" : __DIR__"road3",
  		"southdown" : __DIR__"road1",
]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
