inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
һ���С�Ĳ��ã��տյ�ʲôҲû�У���ȴ��ɨ���쳣�ɾ����ƺ���һ������
��û�С����϶˶���������һ�����ţ�б����λ�׷����ߣ��������㣬�·��ڿ�һ
��ͼ��  
LONG);

	set("type","house");
       set("indoors", "wolfmount");
	set("exits",([
		"out":__DIR__"flowers",
		"south":__DIR__"shuaiyi",
	]) );
	set("objects",([
     		__DIR__"npc/buzhan":1,
    	]) ); 
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}
