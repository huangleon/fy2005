inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
�����Ǹ���ɽׯ��԰һƬ���ܵ���ľ�֣�����һƬ�ž���������ı�ض��ǣ�
����������С·�̳������������̺����֪����Ұ��͵͵�ӹ���С·�Ծ���������
���ʵ�СϪ��Ϫˮ��Ư���������Ҷ������֦Ҷ����ϡ�ɿ���Ϫˮ�����羵���峺
���ס�
LONG);
	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"east":__DIR__"grass1",
		"northwest":__DIR__"senling2",
	]) );
	
	set("coor/x",-10);
	set("coor/y",230);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
