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
		"north":__DIR__"yidao2",
	 	"south":AREA_QUICKSAND"xiaodao2",
	]) );

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
