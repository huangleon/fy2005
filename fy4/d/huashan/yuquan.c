
inherit ROOM;

void create()
{
        set("short", "��ȪԺ");
        set("long", @LONG
��ȪԺλ�ڻ�ɽ���ڣ����ʵǻ�ɽ����ؾ�֮����Ժ������Ȫһ�ɣ�������
������֮�ɿڣ���ȪԺ��֮������Ժ�ڹ�ľ���죬������涣���ʯ��ᾣ�С����
ˮ���������ȣ��羰�续�������������࣬���Ҳ��һЩС̯���ٴ˰�̯������
�˶��۸�����Ʒ��
LONG
        );
    set("exits", ([ 
  		"eastdown" : __DIR__"changpu",
  		"westup" : __DIR__"wuli",
		"northwest" : __DIR__"path1",
	]));
    set("resource/water", 1);
    set("liquid/container", "��Ȫ");   
    set("liquid/name","��Ȫˮ");
   	set("objects", ([
   		__DIR__"npc/seller1" : 1,
   	]));
    set("outdoors", "huashan");

	set("coor/x",-5);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
}

void init(){
	object me;
	me = this_player();
	if ((int)me->query_condition("music") > 0) {
		tell_object(me, "������Զ��������ʧ�ˡ�\n");
		me->clear_condition("music"); 
	}
}
