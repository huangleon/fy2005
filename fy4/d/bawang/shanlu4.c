inherit ROOM;

void create()
{
    set("short", "����կ");

	set("long", @LONG
�����أ����Ѿ��ӽ������ڵĺ��ĵش�����������ʱ��ʱ�ɼ���ɫ���˺�ǿ��
·���ε��������⣬��ںȾơ����������Ӷ�Ǯ������õ�Ҳ��ң���ڡ��ϱ�ͨ
����������·����һ��կ�ţ��������ڽ����ţ����ҽ䱸ɭ�ϣ����������롣
LONG);

	set("type","road");
	set("outdoors", "bawang");
	set("exits",([
		"northdown":__DIR__"shanlu3",
	]) );
	set("objects", ([
		__DIR__"npc/yue_lin":1,
		__DIR__"npc/chen_zhun": 1,
		__DIR__"npc/yi_hu": 1,
		__DIR__"npc/female_bandit": 2,
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
