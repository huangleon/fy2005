// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ܴ����ܵ�Ⱥɽ�����￴���Եú�С��ˮ������䣬����ػ�����������
�����ܣ����ϵİ��ƻ����ر任����״���㼸��������ʱ��Ĵ��ڣ�Ȼ������ĺ�
ˮȴ���㳶�ص���ʵ�У����ǲ�Ҫ���������̫�á�
LONG
        );
   	set("objects", ([
      		__DIR__"npc/frog" : 2,
   	]) );
        set("outdoors","shenshui");
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",20);
	set("underwater",30);
	set("water_damage",10);
	setup();
}

void init()
{
   	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
   	add_action("do_swim", "swim");
}

int do_swim()
{
   	object me, room;
   	int kar, k;
  
   	me = this_player();
   	if( me->is_busy() )
      		return notify_fail("����һ��������û����ɡ�\n");
   	me->start_busy(2);
   	kar = (int)me->query("kar");
   	k = kar - 15; if(k<1) k = 1;
   	message_vision("\n$N�����������ȥ!", me);
   	if(random(kar) < k) {
      		message_vision("$N����ʪ���ܵ������˰���!\n\n", me);
      		room = find_object(AREA_LAOWU"baishui");
	      	if(!objectp(room)) room = load_object(AREA_LAOWU"baishui");
	      	me->move(room);
	      	message("vision", me->name()+"ʪ���ܵشӺ�������������\n", environment(me), me);
   	} else {
      		message_vision("һ�ɰ����ְ�$N���˻���!\n", me);
   	}
   	return 1;
}
