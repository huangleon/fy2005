inherit ROOM;

void create()
{
	set("short", "��Դ����");

	set("long", @LONG
�����ӱ���Զ����������Դ���̣�Ҳ�ͳ������˼�һ������������ʵ��ª��
խ������ţ�С���ߵĴ��ӣ���ƵĴ�ֽ����Ƶĵƹ⡣һ����Ӱ���ͣ��׷��Բ�
����ͷ����������Ͱ��ˮ��׼��������á�
LONG);
	
	set("type","house");
	set("exits",([
		"west":__DIR__"xiaojie3",
	]) );
    	set("objects", ([
        	__DIR__"npc/huo" : 1,
        ]) );

	set("coor/x",30);
	set("coor/y",90);
	set("coor/z",0);
	setup();
}
