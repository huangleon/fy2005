inherit ROOM;

void create()
{
	set("short", "佻�Ϫ");
	set("long", @LONG
һ���峺���׵�Ȫˮ�����Ե�ɽ�н����������������д��ӵ��أ�����С����
������̣�����ɽ��������Ϫˮ�и�ɫ�ͷ׵Ļ�������Ϫˮ���������ʣ�һ������
�续��Ȫˮǳǳ���У��������ϣ������������ģ���ɽ���
LONG);

	set("type","waterbody");
	set("exits",([
		"northwest":__DIR__"brook4",
        	"east":__DIR__"pubyard",
	]) );
       	set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/xiaoxiao":1,
    	]) ); 
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
	if(interactive(this_player()))
	{
		remove_call_out("dropflower");
		call_out("dropflower",random(10)+10,this_player());
	}
}
int dropleaf(object me)
{
	object dropflower;
	if(environment(me) == this_object())
	{
		tell_object(me,"һ���仨��Ϫˮ����Ʈ�˹�����������\n");
        	dropflower = new(__DIR__"obj/dropflower");
		dropflower->move(this_object());	
	}
}