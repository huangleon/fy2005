// �� ˼· by Sinny/Silencer@fy4.
// ������������ 
// ʮ���������
// ���񳯷����� 
// �̺�������:  
// ����ˮ������
// ����ɢ

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg,area;
	object weapon,room;
	object * stuff;
	int skill, your_exp, my_exp, damage, i, qin;

	if (me->is_ghost())
		return notify_fail("�����ǹ�꣬�����뷨�Ȼ�����ɡ�\n");
	
	stuff = all_inventory(me);
	qin=0;
	for (i=0;i<sizeof(stuff) ;i++){
		if(qin < stuff[i]->query("timbre")){
		  qin = stuff[i]->query("timbre");
		}
	}  
	if(!qin && userp(me)) return notify_fail("��������Ǵ����ˡ�\n");
	
	skill = me->query_skill("music",1);		
	if (!skill)
		return notify_fail("��������һ�ϲ�ͨ��Ϲ���˼��£��پ���Ȼ��ζ��\n");
		if (me->query("annie/music_choose") != 2)
		return notify_fail("���������ƺ�ûѧ������\n");

	if (skill < 150)
		return notify_fail("�㷢�ִ��׹��ڸ��������Ҫ150�����ٵ��������ࡣ\n");

	if (me->is_fighting())
	        return notify_fail("ս���в��ܵ��ࡺ����ˮ������\n");
    
  	if (stringp(me->query_temp("no_move")))
		return notify_fail(me->query_temp("no_move"));	
		    
	room = environment(me);
	area = room->query("outdoors");
	if (!area) 
		return notify_fail(CYN"�����ֲ����˼��£�������ɱ������������Ȼ���¡�\n�㲻�����⣬�ɺ��Ҳ���������\n"NOR);	
  
  	if( me->query("atman") < 500 )
		return notify_fail("���ࡺ����ˮ��������Ҫ��������������\n");
	if (userp(me)) me->add("atman",-500);
               
	message_vision(CYN"
$NԶ���̿գ�������ˮ��ӳ������ϸ�ľ������͵��������������������
����������ɱ֮��ϸ�����࣬�������ޣ�������š�     

\n"NOR,me);
	call_out("move_him",1+random(4),me, area);
	return 1;
}



int move_him(object me, string area)
{

	object room;
	string room_name;
	
	// Put checks here to ensure legitimacy
	
	if (!me || me->is_ghost())	return 1;
	
	if (me->is_fighting()|| me->is_busy())	return 1;		
	if (environment(me)->query("no_fly"))	return 1;
	if (stringp(me->query_temp("no_move")))	return 1;
	room = environment(me);
	area = room->query("outdoors");
	if (!area) return 1;
				
	message_vision(CYN"һ�����գ���������֮������������һֻ���׼���������������$N�����ԡ�\n\n"NOR,me);
	message("vision",CYN""+me->name()+"���Ϻױ��������ĺ׾��ڿն�ȥ��������\n"NOR,environment(me),me);
	tell_object(me,"�����Ϻױ��������ĺ׾��������ڿն���\n");
        
        tell_object(me, WHT"
        
        
        		�Ƽ�
        
    ���Ϸ�����������ǰ����ƬƬ��������Ƴ���ϡ�ɼ�������������
    
    
    
    	\n"NOR);
	
	if (area == "tieflag" && file_name(environment(me))[0..11]!="/d/changchun")
		area = "nada";
	
	switch (area) {
		case "tieflag":   room_name = AREA_BAIYUN"jietiandian";
				  break;	
		case "baiyun":	  room_name = AREA_FY"fysquare";
				  break;	
		default:	  	  room_name = AREA_CHANGCHUN"moonding";
	}
	seteuid(ROOT_UID);
        room = find_object(room_name);
	if (!room) room = load_object(room_name);
	seteuid(geteuid());
	
	message("vision",CYN"\n���������"+me->name()+"�����״��������\n"NOR,room,me);
	tell_object(me,"���������ؽ������棬�����ºױ���\n\n");
	TASK_D->flying_risk(me);
	me->move(room_name);
	message_vision(CYN"��������$N��ͷ�������������˼�Ȧ��һ��������չ���������֮�С�\n"NOR,me);
	return 1;
}
		