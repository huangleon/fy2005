// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
    	set_name("ý��", ({ "mei po","po" }) );
    	set("title", "ԧ��ͤ");
    	set("gender", "Ů��" );
    	set("age", 43);
    	set("long", "һλ�����ܸɵ���ý�š�\n");
    	
    	set("combat_exp", 10000);
    	set("attitude", "friendly");
    	set("inquiry", ([
        	"��Լ" : "�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
        	"marry" : "�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
        	"�Ǽ�" : "������԰���Ļ�Լ��¼�ڰ���register spouse_id��",
        	"register" : "������԰���Ļ�Լ��¼�ڰ���register spouse_id��",
        ]) );
    
    
    	set_skill("dodge", 500);
    	set_skill("unarmed", 300);
    	setup();
    
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/food_item/wedding_candy");
    	carry_object("/obj/food_item/wedding_candy");
    	carry_object("/obj/food_item/wedding_candy");
}

void init()
{
    
    	add_action("do_marry", "marry");
    	add_action("do_register", "register");    
    	add_action("do_unmarry", "divorce");
}

int do_marry(string arg) //there is a marry emote, ruined all the messages.
{
    	object obj, me, room;
    	object ob;
    	int i;
    	string myclass,otherclass;
    	me = this_player();
    	if( me->query("marry"))
        	write("���Ѿ��ͱ����л�Լ�˰�?���ﲻ�����ػ�ġ�\n");
    	else if(!arg || !objectp(obj = present(arg, environment(me))))
        	write("�����˭�޽���Ե��\n");
    	else if( obj->query("marry"))
        	write("��Ķ����Ѿ��ͱ����л�Լ�˰�?���ﲻ�����ػ�ġ�\n");
    	else if((int)me->query("age")<16 && (string)me->query("gender")=="����" ||
        	    (int)me->query("age")<14 && (string)me->query("gender")=="Ů��")
        	write("��̫С������ô��������\n");  
    	else if((myclass = me->query("class")) == "bonze" || myclass == "wudang" ||
        		myclass == "lama" || myclass == "shaolin" || myclass == "taoist" ||
            		(otherclass = obj->query("class")) == "bonze" || myclass == "wudang" ||
            		otherclass == "lama" || otherclass == "shaolin" || myclass == "taoist")
        	write("�������ǲ����Խ�顣\n");
    	else if (me->query("once_gelun")==1)
    		write("����˸��״�ʦ��ô����,���ǰ�ܸø���˵һ����.\n");
    	else if (me->query("once_sanqing"))
    		write("���幬����λ���������������ǵĵ��ӽ��ǰҪ��ȥ����к�(ask master about marriage)��\n");
    	else if( !living(obj) )
        	write(obj->name() + "�Ѿ��޷�����޽���Ե�ˡ�\n");
    
    	else if(obj==me)
        	write("������������\n");
    	else if(!userp(obj))
        	write("��ֻ�ɺ�������飮\n");
    	else if((string)obj->query("gender")== (string)me->query("gender"))
        	write("ͬ������̫������ʱ���˰ɣ�\n");



    	else if( userp(obj) && !obj->query_temp(me->query("id") + "m"))
    	{
        	message_vision(MAG "\n$N����$n˵����" 
                       + RANK_D->query_self(me) 
                       + me->name() + "��Ը���"
                       + RANK_D->query_respect(obj) + 
                       "��Ϊ��\n\n"NOR, me,obj);           
        	me->set_temp(obj->query("id") + "m",1);
        	tell_object(obj, MAG "�����Ը��ͶԷ���Ϊ�򸾣�����Ҳ��" 
                	    +me->name() + "("+(string)me->query("id")+
                    		")"+ "��һ�� marry ָ�\n"NOR);
        	write(MAG "�����㼱�����������������˵ͬ��...\n"NOR);
    	        //	This is a small blessing for some mud players, a couple in real life 
        	//	I will force them to solve ÷����, add some spice to their marriage 
        	//		-- by silencer@fy4.
    	        if ((me->query("id")=="anniew" || me->query("meihua-test") )&& !me->query("blessing")) {
        		message_vision(HIB"\n��Ȼ����һ������ķ磬���쬵��������Ϲι������������ۣ�ͻȻ����\n"NOR, me);
        		message_vision(HIB"�ƺ��и���Ӱվ��$N�����$N�Ȼһ��������ת��ȴ�ѱ�������Ѩ����\n\n��Ӱ��$NЮ�����£����Ƽ�������ǵ����Ͻ����˳�ȥ������\n\n"NOR, me);
                	room=find_object(AREA_QIANJIN"basement");
                	if(!objectp(room))
                        	room=load_object(AREA_QIANJIN"basement");
                	me->set_temp("marks/meihuadao", 1);
                	me->move(room);		
             		message_vision(HIR"\n÷������$N�����˵����ҽ������С���ϣ�һ��Ī����״����ζϮ����$N��Ϣһ\n�ϣ����˹�ȥ��\n"NOR,me);
             		me->unconcious();
               		return 1;
               }  
    	}
    	else
    	{
        	//	This is a small blessing for some mud players, a couple in real life 
        	//	I will force them to solve ÷����, add some spice to their marriage 
        	//		-- by silencer@fy4.
        	if ((me->query("id")=="anniew" || me->query("meihua-test") )&& !me->query("blessing")) {
        		message_vision(HIB"\n��Ȼ����һ������ķ磬���쬵��������Ϲι������������ۣ�ͻȻ����\n"NOR, me);
        		message_vision(HIB"�ƺ��и���Ӱվ��$N�����$N�Ȼһ��������ת��ȴ�ѱ�������Ѩ����\n\n��Ӱ��$NЮ�����£����Ƽ�������ǵ����Ͻ����˳�ȥ������\n\n"NOR, me);
                	room=find_object(AREA_QIANJIN"basement");
                	if(!objectp(room))
                        	room=load_object(AREA_QIANJIN"basement");
                	me->set_temp("marks/meihuadao", 1);
                	me->move(room);		
             		message_vision(HIR"\n÷������$N�����˵����ҽ������С���ϣ�һ��Ī����״����ζϮ����$N��Ϣһ\n�ϣ����˹�ȥ��\n"NOR,me);
             		me->unconcious();
               		return 1;
               }        
        	me->set("marry",obj->query("id"));
        	me->set("marry_name",obj->query("name"));
        	obj->set("marry",me->query("id"));
        	obj->set("marry_name",me->query("name"));
        
        	message_vision(MAG "��ϲ $N �� $n ��һ�����ϲ����Ե��\n"NOR,
                       obj, me);
        	if(me->query("gender")=="����")
            	CHANNEL_D->do_sys_channel("info",sprintf(
                	"%s(%s)��%s(%s)ϲ����Ե��", 
                	me->name(1),me->query("id"), obj->name(1), obj->query("id")));
        	else
            		CHANNEL_D->do_sys_channel("info",sprintf(
                		"%s(%s)��%s(%s)ϲ����Ե��", 
                		obj->name(1), obj->query("id"),me->name(1),me->query("id")));
    	}
    	return 1;
}

int do_unmarry(string arg)
{
    	object marry_card1,marry_card2,  me;
    	object couple_ob;
    	int i, have_marry;
    	string target, tmpstr1, tmpstr2,str1,str2;
    	string cardname;
             
    	me = this_player();       
    	if (!me->query("marry"))  write("�㻹δ�л�Լ����\n");
    	else if(!objectp(couple_ob =
                present(target=(string)me->query("marry"), environment(me))))
        	write("��İ������ڲ��ڳ�.\n");

    	else if( userp(couple_ob) && !couple_ob->query_temp(me->query("id")+"d"))
    	{
        	message_vision(MAG "\n$N����$n˵����" + RANK_D->query_self(me) 
                       + me->name() + "�����ǽ����Լ��!����?\n\n"
                      NOR, me, couple_ob);           
        	me->set_temp(couple_ob->query("id")+"d",1);
        	tell_object(couple_ob, MAG "�����Ը������Լ������Ҳ"
                    + "��һ�� divorce ָ�\n"NOR);
        	write(MAG"������ֻ�е���" +couple_ob->query("name")+"ͬ����...\n"NOR);
    	} else { 
        	me->delete("marry");
        	couple_ob->delete("marry");
        	me->add("divorced",1);
        	couple_ob->add("divorced",1);
        	message_vision(MAG " $N �� $n �����ڿ�ʼ�����Լ�����ٻ顢Ů�ټ޻�����ɣ�\n"NOR,
                       couple_ob, me);
        	if(me->query("gender")=="����")
            		CHANNEL_D->do_sys_channel("info", sprintf(
                	"%s(%s)��%s(%s)�����Լ�����ٻ顢Ů�ټ޻�����ɣ�", me->name(1),
                	me->query("id"),couple_ob->name(1),couple_ob->query("id")));
        	else
            	CHANNEL_D->do_sys_channel("info", sprintf(
                	"%s(%s)��%s(%s)�����Լ�����ٻ顢Ů�ټ޻�����ɣ�",couple_ob->name(1),
                	couple_ob->query("id"),me->name(1),me->query("id")));
    	}
    	return 1;
}

int do_register(string arg)
{
    	object obj, me;
    	object ob;
    	int i;
    	string myclass,otherclass;
    	me = this_player();
    	if( !me->query("marry"))
        	write("�㻹û�л�Լ��Ҫ�Ǽ�ʲô��\n");
       
    	else if(!arg || !objectp(obj = present(arg, environment(me))))
        	write("�����˭�Ǽǽ���¼��\n");
    /*else if(!objectp(obj =
                present(target=(string)me->query("marry"), environment(me))))
        write("��İ������ڲ��ڳ�.\n");
    */

    	else if( !me->query("id") == obj->query("marry"))
        	write(obj->name()+"��������Ļ�Լ��ż����������ʲô��\n");
    	else {
        	me->set("marry_name",obj->query("name"));
        	obj->set("marry_name",me->query("name"));
        	message_vision(YEL" $N �� $n �Ļ�Լ�Ѿ���¼�ڰ���\n"NOR,obj, me);
    	}
    	return 1;
}

