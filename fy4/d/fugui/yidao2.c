inherit ROOM;

void create()
{
	set("short", "�Ͼ����");

	set("long", @LONG
�������ϱ�����ķϾ�����������������ȣ�ʱ�����������ȥ�����ǿ���
�ܲݣ�˷����ɱ������Ұ�������������ɳҲ��ʱ�������˵�˫�ۣ�Ҳ������ǰ��
������Ρ�
LONG);
	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"south":__DIR__"yidao1",
		"north":__DIR__"yidao3",
	]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
