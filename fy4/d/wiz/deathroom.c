// Tie@fy3
inherit ROOM;

void create()
{
	set("short", "��˹ά�̼���Ӫ");
	set("long", @LONG
�����Ǵ�������в�������destruct NPC�ĵط���NPC����˴��󣬽���һ����
����ʧ���������Ʒ����������ˢ��ʱ��ʧ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	]));
        set("no_fight", 1);
		set("no_magic", 1);

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",-10000);
	setup();
}

void byebye(object me){
	if (!me)	return;
	if (environment(me)!= this_object())	return;
	destruct(me);
	return;
}	
		

void init(){

	object owner, me = this_player();
	if (userp(me))	return;
	if (objectp(owner = me->query("possessed")))
	if (userp(owner))	return;

	me->delete("can_fly");
	call_out("byebye", 60, me);
}


			
		
		