inherit ROOM;

void create()
{
	set("short", "�Ͼ����");
	set("long", @LONG
��������������ķϾ�����������������ȣ�ʱ�����������ȥ�����ǿ���
�ܲݣ�˷����ɱ������Ұ�������������ɳҲ��ʱ�������˵�˫�ۣ�Ҳ������ǰ��
������Ρ�
LONG);
	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"xiaodao2",
	 	"west" : __DIR__"huangyie0",
	]) );

	set("coor/x",-900);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
