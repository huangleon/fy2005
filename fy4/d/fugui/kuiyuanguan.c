inherit ROOM;

void create()
{
	set("short", "��Ԫ��");

	set("long", @LONG
������������������ô���ҥ�����Ϲ����Ѽ����Ԫ�ݵ��Ͼơ�����ȷ������
ô��С����������Ƶ����ز��Ļ��������������ˣ���Ԫ�ݲ��󣬵ط�Ҳ�ܼ�����
����������ƺȵ��˻��治�٣����ſ��Ǹ���̫���ŷ硱�ľ���ӭ��Ʈ��������
���ﻹ���м�����ɫ����������æ�Ŵ����ˡ�
LONG);

	set("type","house");
	set("exits",([
		"west":__DIR__"xiaojie2",
	]) );

	set("objects",([
		__DIR__"npc/huoji" : 1,
	]));
	set("coor/x",30);
	set("coor/y",100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
