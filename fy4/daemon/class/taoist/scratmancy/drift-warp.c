#include <ansi.h>
#include <command.h>
#include <login.h>
inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
         string err;
         int extra;
         
        if(me->query("class")!="taoist")
         	return notify_fail("ֻ�����幬���Ӳſ��Ի�����\n");

        if((int)me->query_skill("scratmancy",1) < 50)
                return notify_fail("���Ŷݷ�������Ҫ50�����������\n");

        if( sheet->name() != "�ҷ�ֽ" )
                return notify_fail("�����Ҫ�����ҷ�ֽ�ϣ�\n");
	
        if( (int)me->query("mana") < 100 ) 
		return notify_fail("���Ŷݷ�������Ҫ100�㷨����\n");
	write("��Ҫ�ڷ���дʲô��");
	input_to( (: call_other, __FILE__, "select_target", me,sheet :));

	return 1;
}

void select_target(object me, object sheet,string name)
{
	object ob,newsheet;
	string fplace;
	int level;
	
	if( !name || name=="" ) {
		write("��ֹд����\n");
		return;
	}

	switch(name)	{
		case "fengyun":
		case "���Ƴ�":
			level = 50;
			fplace="���Ƴ�";
			break;
		case "dazhaosi":
		case "������":
			level = 60;
			fplace="������";
			break;
		case "songguan":
		case "�ɹ���":
			level = 80;
			fplace="�ɹ���";
			break;
		case "daimiao":
		case "���":
			level = 80;
			fplace="���";
			break;
		case "bianfudao":
		case "����":
			level = 100;
			fplace="����";
			break;
		case "biancheng":
		case "�߳�":
			level = 130;
			fplace="�߳�";
			break;
		case "baiyundao":
		case "���Ƶ�":
			level = 150;
			fplace="���Ƶ�";
			break;
		default:
			level = 50;
			fplace="�������";
			break;
	}
	
	if (me->query_skill("scratmancy",1) < level) {
		write ("����������̫�ͣ��޷���Ӧ��������񡣣���"+level+"����\n");
		return;
	}
	
	if (me->query("mana")< 100) {
		write ("������Ҫ100�㷨����\n");
		me->add("mana", -50);
		me->force_status_msg("mana");
	}
	
	sheet->add_amount(-1);
	seteuid( geteuid(me));
        newsheet = new("/obj/item/magic_seal");
        newsheet->set_name(YEL "�����" NOR, ({ "drift-warp sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->set("burn_person",me);
        newsheet->move(me);
        me->save();
       	
	newsheet->set("long","һ�ŵ��ҵĶ������������׭��д��"+fplace+"�����֡�\n");
	newsheet->set("flying_place",fplace);
	newsheet->set("level", level);
			
        message_vision("$Nд��һ��ȥ"+fplace+"�Ķ������\n" NOR, me);
        	
        return ;
}

int do_warp(object sheet)
{
        object env, me;
        string fplace;
        me=this_player();
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty"))
    		return notify_fail("�˵ز���ʹ�ö������\n");  
		if (me->is_fighting())
    		return notify_fail("��ѽ�����ʱ���շ���û���õģ���������Ѿ���Ӱɡ�\n");  
	
		if (stringp(this_player()->query_temp("no_move")))
        	return notify_fail(this_player()->query_temp("no_move"));
        	
		me->start_busy(2+random(2));
		fplace=(string)sheet->query("flying_place");
        env = environment(me);
        message("vision",me->name()+WHT"��̤������������һ�Ŷ������ \n"NOR, env,me);
        tell_object(me, WHT"���̤������������һ�Ŷ������ \n"NOR);
        message("vision",YEL "ƽ��ӿ��һ����ã������"+me->name()+YEL"����Ӱ��û��������... \n"NOR,env,me);
	
	if(sheet->query("burn_person")==this_player())
		call_out("move_him",1+random(4),this_player(),fplace);
	else
		message_vision("���ʲô��û�з�����\n",this_player());
	return 1;
}



int move_him(object me,string fplace)
{
	string place;		
  	message("vision", "WHT ��������ɢȥ��$N�Ѿ���ʧ����Ӱ���١�  \n"NOR
  		,me,({me}));
        message("vision",
                MAG "��Χ�ľ�ɫ��ɰ������ȥ���㲻���е�ͷ��Ŀѣ�� \n"
YEL "��е���Χ�ľ�ɫ�����������������Ѿ���������һ���ط��� \n\n"NOR, me);
 	switch(fplace) {
 		case "�������":	// ding_sq
 			place="/d/taoguan/da_dian";
 			break;
 		case "������":		// ding_gw
 			place="/d/guanwai/templeyard";
 			break;
 		case "�ɹ���":		// ding_hs
 			place="/d/huangshan/songgu";
 			break;
 		case "���":		// ding_dm
 			place="/d/daimiao/tongting";
 			break;
 		case "���Ƴ�":	// ding_fy
 			place="/d/fy/hiretem";
 			break;
 		case "����":		// ding_bat
 			place="/d/bat/room2";
 			break;
 		case "�߳�":		// ding_bc
 			place="/d/biancheng/temple";
 			break;	
 		 case "���Ƶ�":		// ding_by
 			place="/d/baiyun/jietiandian";
 			break;	
	}
	if(!stringp(place))
		place="/d/taoguan/da_dian";
	TASK_D->flying_risk(me);
	me->move(place);
	message("vision",YEL "����Χ��Ȼ����һ��ַ磬"+me->name()+"����Ӱ�ƺ��ӷ���������������ǰ�� \n"NOR,
		place, ({me}) );
      
        return 1;
        
}
 


/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/
