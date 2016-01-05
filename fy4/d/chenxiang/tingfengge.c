#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");

	set("long", @LONG
����������̴��컧�����в��õ��൱���������е���̴֧�㣬��ζ����Ʈ��
���е����ٻ��㣬���������Ŀ���������ʯ�ذ���бб���Ÿ��ˣ�������ס����
�ţ�һ�ѷ����ĳ�������һ�ԡ�
LONG);

		set("type","indoors");
		set("exits",([
			"east":__DIR__"fyyard",
		]) );
        set("indoors", "chenxiang");
		set("coor/x",10);
		set("coor/y",60);
		set("coor/z",0);
		set("objects",([
     		__DIR__"npc/bai": 1,
     		__DIR__"obj/floor": 1,
    	]) );
		setup();
}


int do_answer(string arg)
{
	object *inv;
	int i;
	int div;
	object me,bai;
	object room,floor;

	me = this_player();
	room = this_object();
	bai = present("bai yujing", room);
	floor = present ("stone floor", room);
	
	div =0;
	inv = all_inventory(floor);
        for(i=0; i<sizeof(inv); i++)
        	if(inv[i]->query("baiyujing"))
        	{
			div = 1;
			destruct(inv[i]);
        	}

        if( arg != "love" &&  arg != "hate") 
                return notify_fail("��Ҫ�ش�ʲô����\n");
        if( arg == "love" ) 
        {
                message_vision( HIR "\n$N��Ҳ�������̴������ô���˵�΢Ц������������ֻ������
�మ���˲Ż�Ц����ô��Ԭ�����ǿ̹����ĵذ������ѽ��\n"NOR, me);
		if (div)
			call_out("goodresult",2,bai,me,room);
		else
			call_out("midresult",2,bai,me,room);
        }
        else if( arg == "hate" )
        {
            	message_vision( HIB "\n$N�����˰��죬ҡҡͷ�����������ջ�ˮ���������ţ�\n"NOR, me);
        	call_out("badresult",2,bai,me,room);
        }
	return 1;
}

int gethim(object target,object me,object room)
{
	if(!target || !me ) return 1;
	if(environment(me) == room)
	{
        	message_vision("$Nһ�仰��˵���Ҵ�ææ���뿪�ˡ�\n",target);
        	target->move(this_object());
        	message_vision("$N���˽�����\n",target);
		return 1;
	}
	return 1;
}

void goodresult(object bai,object me,object room)
{
	object yuan,wei;
	yuan = find_real_living("yuan zixia");
	wei = find_real_living("wei tianying");
	
	if (yuan && wei && bai)
	{
		wei->remove_all_killer();
		call_out("gethim",0,wei,me,room);
		call_out("gethim",0,yuan,me,room);
		call_out("event",4,wei,yuan,bai,me,1);
		me->start_busy(4);
		return;
	}
	return;
}

void event(object wei,object yuan,object bai,object me,int i)
{
	switch(i)
	{
	case 1:	
        	message_vision( HIY "\n$N���������񾩺�$n��գ��գ�۵����汧Ǹ��������Ҫ�Ҷ���ɱ���㡣\n\n"NOR,yuan,me);
		break;
	case 2:
        	message_vision( GRN "$N��ǰһ�ݣ��ż����������������������߰����$n��\n\n"NOR, yuan,bai);
		break;
	case 3:
        	message_vision( HIC "$N��Хһ��������ӥ�����գ�����Ծ�����һ�ѳ���������\n\n$N˲Ϣ֮�䣬����������ˮ����������\n\n�������������ӡ�\n\n�ǹ�ɢ��Ѫ���֡�\n\n\n"NOR, bai,wei);
		wei->die();
        	message_vision( HIY "$N��$n����Ц������ʶ®ɽ����Ŀ��ֻԵ���ڴ�ɽ�У���л��λ" + RANK_D->query_respect(me)+ "\nָ���Խ�\n\n"NOR, bai,me);
			
        	REWARD_D->riddle_done( me, "���ϰ���", 100, 1);
        	
        	message_vision( HIY "$N����Գ�ۣ���ס$n������ϸ��������һЦ��ƮȻ��ȥ��\n"NOR, bai,yuan);
		if (!REWARD_D->imbue_check( me, "���ϰ���"))
				call_out("imbue_event2", 3, me);
		me->stop_busy();
/*		if(!me->query("imbue/yuan")){
				call_out("imbue_event2", 3, me);
		}*/
		destruct(yuan);
		destruct(bai);
		return;
	}
	i=i+1;
	call_out("event",2,wei,yuan,bai,me,i);
}

void badresult(object bai,object me,object room)
{
	object yuan,wei;
	yuan = find_real_living("yuan zixia");
	wei = find_real_living("wei tianying");
	
	if (yuan && wei && bai)
	{
		wei->remove_all_killer();
		call_out("gethim",0,wei,me,room);
		call_out("gethim",0,yuan,me,room);
		call_out("badevent",2,wei,yuan,bai,me,1);
		me->start_busy(4);
		return;
	}
	return;
}

void badevent(object wei,object yuan,object bai,object me,int i)
{
	switch(i)
	{
	case 1:	
        	message_vision( HIB "$N��Ц�����������ǵ���Ȫ���ɡ�\n$N���г�������������������$n��\n\n"NOR,wei,bai);
		break;
	case 2:
        	message_vision( HIB "$N����ؿ���$nһ�ۣ�����һ������ȻһЦ���򵶷档\nѪ��ɽ���$N��ʱ�������ɡ�����\n\n"NOR, yuan,bai);
		yuan->die();
		break;
	case 3:
        	message_vision( HIB "$N����һ������$n��\n$n���챯˻һ������\n\n"NOR,wei,bai);
        	message_vision( HIB "Ѫ���е�Ԭ��ϼ��Ҳ�޷�������������Ц�ݣ�$N����Ժ�з�ɢƮ���Ŵ�Ѫ�����ٻ�����\n\n$N������Ѫ���У�����������Ԭ��ϼ��ʬ��\n\nһ�硢һ�硣��$NŲ�������塣��ʯ��������һ����Ŀ���ĵ�Ѫ�ۡ���\n\n$N���������Ԭ��ϼ����ͷһ�ᡣ��\n\n\n"NOR, bai);
		bai->die();
		
        REWARD_D->riddle_done( me, "���ϰ���", 100, 3);
        	message_vision( HIR "$N�ٺ���Ц�ţ��ڳ���һ��Ҳ���ܻ\n"NOR, wei);
		wei->kill_ob(me);
		me->kill_ob(wei);
		me->stop_busy();
		if (!REWARD_D->imbue_check( me, "���ϰ���"))
				call_out("imbue_event", 5, me);
		return;
	}
	i=i+1;
	call_out("badevent",2,wei,yuan,bai,me,i);
}

void midresult(object bai,object me,object room)
{
	object yuan,wei;
	yuan = find_real_living("yuan zixia");
	wei = find_real_living("wei tianying");
	
	if (yuan && wei && bai)
	{
		wei->remove_all_killer();
		call_out("gethim",0,wei,me,room);
		call_out("gethim",0,yuan,me,room);
		call_out("midevent",2,wei,yuan,bai,me,1);
		me->start_busy(4);
		return;
	}
	return;
}

void midevent(object wei,object yuan,object bai,object me,int i){
	object petal, ob;
	switch(i)
	{
	case 1:	
        	message_vision( HIW "$N��$nգ��գ�۵����汧Ǹ��������Ҫ�Ҷ���ɱ���㡣\n\n"NOR,yuan,bai);
		break;
	case 2:
        	message_vision( HIW "$N����Ծ��$n��ߣ�����⿪$n��Ѩ����\n\n"NOR, yuan,bai);
		break;
	case 3:
        	message_vision( HIW "$N�ƺ���Ϳ���$n��ͼ���������Ź���Ĺ�â����$n�����š�\n\n$n��������������񾩵��֣�������û�ܹ���������\n\n"NOR, wei,yuan);
		yuan->die();
	case 4:
        	message_vision( HIW "$N����һת��˳��ͱ��$n�����š�\nѪ��ɽ���$n��������Ԭ��ϼ��ʬ��������\n\n"NOR, wei,bai);
		bai->die();
		
		REWARD_D->riddle_done( me, "���ϰ���", 100, 2);
        	petal = new(__DIR__"obj/petal");
		ob = present("floor", this_object());
		if(objectp(petal)) {
			petal->move(ob);
		}
        	message_vision(MAG"\n������ᴵ����һ���Ѫ�����ٻ��������Ʈ���ڵذ��ϡ�\n"NOR, me);
        	message_vision( HIR "$N����Ѫ���е�ʬ�壬������Ц������\n"NOR, wei);
		wei->kill_ob(me);
		me->kill_ob(wei);
		me->stop_busy();
		if (!REWARD_D->imbue_check( me, "���ϰ���"))
			call_out("imbue_event", 5, me);
		return;
	}
	call_out("midevent",2,wei,yuan,bai,me,i+1);
}

void answer_notify(object bai, int i)
{
	add_action("do_answer","answer");
}


void imbue_event(object me){
	object weapon, petal, ob, *inv, obj;
	string prop;
	int i;
	mapping data;
	if(!interactive(me) || environment(me) != this_object()) {
		return 0;
	}
	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	if(!objectp(weapon)){
		if(!objectp(obj)) {
			message_vision(MAG"\n������ᴵ����һ���Ѫ�����ٻ��������Ʈ���ڵذ��ϡ�\n"NOR, me);
		} else {
			message_vision(MAG"\n������ᴵ����һ���Ѫ�����ٻ��������Ʈ����$N��" + obj->name() + MAG"�ϡ�����\n"NOR,
					me);	
			message_vision(MAG"��������Ļ��䣬" + obj->name() + MAG"��Ȼ��ɡ�\n"NOR, me);
		}
	}else{
		message_vision(MAG"\n������ᴵ����һ���Ѫ�����ٻ��������Ʈ����$N��" + weapon->name() + MAG"�ϡ�����\n"NOR,
				me);
		message_vision(MAG"�������ȥ��һ˿����������Ѫ������������$N��" +
				weapon->name() + MAG"�ϣ���Ѹ����ȥ��\n"NOR, me);
	}
	data = ([
		"name":		"���ϰ���",
		"target":	me,
		"att_3":	"random",
		"att_3c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);	
	return ;
}


void imbue_event2(object me){
	object weapon, ob, *inv, obj;
	string prop;
	int i;
	mapping data;
	if(!interactive(me) || environment(me) != this_object()) {
		return 0;
	}

	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	if(!objectp(weapon)){
		if(!objectp(obj)) {
			message_vision(MAG"\n����������������Ӱ����Զȥ��������Ĵ������ٻ������΢����Ʈ�衣\n"NOR, me);
		} else {
			message_vision(MAG"\n����������������Ӱ����Զȥ���ٻ������΢����Ʈ�衣һ�����ٻ��������Ʈ����$N��" 
					+ obj->name() + MAG"�ϡ�����\n"NOR, me);	
			message_vision(MAG"��������Ļ��䣬" + obj->name() + MAG"��Ȼ��ɡ�\n"NOR, me);
		}
	}else{
		message_vision(MAG"\n����������������Ӱ����Զȥ���ٻ������΢�������衣һ�����ٻ��������\nƮ����$N��" 
				+ weapon->name() + MAG"�ϡ�����\n"NOR, me);
		message_vision(MAG"�������ȥ��һ˿�����������Ϻ�ɫ����������$N��" +
				weapon->name() + MAG"�ϣ���Ѹ����ȥ��\n"NOR, me);	
	}

	data = ([
		"name":		"���ϰ���",
		"target":	me,
		"att_3":	"random",
		"att_3c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);	
	return;
}


