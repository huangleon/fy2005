
inherit ROOM;

void create()
{
	set("short", "��ɽ·");
	set("long", @LONG
��������������·��ȴ��ƽ̹���������߶���ïʢ�����֣��������ʱ������
�������������ķҷ�����һ����ʹ�����ؿ��ʣ�����һ�з��ա������������
�ķ�϶��ɼ����䵱�۵ĺ�ɫΧǽ��
LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"rock",
		"southup" : __DIR__"wudang",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}
