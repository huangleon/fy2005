inherit ROOM;

void create()
{
	set("short", "����Ǯׯ");

	set("long", @LONG
��Ȼ˵������ԭ��ʡ��Ǯׯ�������Ϲ�������¢�ϣ����ڼ������ϣ����ǻ���
���Լ�������俪�˰���������ֺŵļ���Ǯׯ�����мӣ�������ƽ�����⻹��
�����ϰ���������ֺǺǵ����ڹ�̨�������۾�����Ҫ�һ�����Ǯ���������ſ�
���ӣ�������
LONG);

	set("type","house");
	set("exits",([
		"east":__DIR__"xiaojie4",
	]) );
	set("objects",([
		__DIR__"npc/cai":1,
	]) );
	set("item_desc", ([
        	"sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ�ҡ�
withdraw    ��ȡ��
deposit     ����Ǯ�ҡ�
balance     ��Ѱ��
loan        ��Ǯׯ��Ǯ��
TEXT
        ]) );

	set("coor/x",10);
	set("coor/y",80);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}