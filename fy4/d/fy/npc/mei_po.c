// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
    	set_name("ý��", ({ "mei po","po" }) );
    	set("title", "ԧ��ͤ");
    	set("no_arrest",1);
    	set("gender", "Ů��" );
    	set("age", 43);
    	set("long", "һλ�����ܸɵ���ý�š�\n");
    	
    	set("combat_exp", 10000);
    	set("attitude", "friendly");
    	set("inquiry", ([
        	"��Լ" : 	"�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
        	"marry" : 	"�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
       		"���":		"�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
       		"divorce":	"�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
        	"desert":	"�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
        	"����":		"�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
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
    	add_action("do_unmarry", "divorce");
		add_action("do_desert","deserted");
}


int do_desert(string arg){
	
	object me;
	string name_c,file;
	object spouse,owner;
	int duration,flag;
	mixed info;
	
	seteuid(getuid());
	
	me = this_player();
	
    if (!stringp(name_c = me->query("marry")))
    	return notify_fail("�㻹δ�л�Լ������ʲô�ң�\n");

	if (!arg)
		return notify_fail("��Ҫ��˭��飿\n");
		
	if (arg != name_c)
		return notify_fail("ý��˵���ǲ��������һ��ɣ�\n");
		
	if (me->query("jiebai"))
		return notify_fail("ý��˵�������û������������ɡ�\n");
		
	if (objectp(spouse = find_player(name_c)))
		return notify_fail(spouse->name(1)+"����������ô���Ҿ����ˡ�\n");
		
	owner = FINGER_D->acquire_login_ob(name_c);
	
	flag = 1;
	
	if (!owner) flag = 0;
	else {
		spouse = LOGIN_D->make_body(owner);		
		if (!spouse) flag = 0;
		else if (!spouse->restore())	flag = 0;
	}
	
	// Purged or suicided. ֻ��Ҫ���Լ�������
	if (!flag) {
		message_vision(CYN"ý��̾�˿���˵�������ĺ��ӣ�ԭ�����Ѿ������������ˣ��ҾͰ����ɡ�\n"NOR, this_object());
        CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)�����������%s(%s)֮��Լ�Զ������", 
                me->query("marry_name"),
                me->query("marry"),
                me->name(1),
                me->query("id")));
		me->delete("marry");
        me->add("divorced",1);
        me->delete("marry_name");
        return 1;
     }
	
	// �������� s-f ����Loginһ����ͬid��
	if (spouse->query("marry")!= me->query("id")
		 && spouse->query("marry_name")!= me->name(1)){
		 message_vision(CYN"ý��̾�˿���˵�������ĺ��ӣ�ԭ�������һ���Ѿ�����ԭ�����ˣ��ҾͰ����ɡ�\n"NOR, this_object());
        CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)�����������%s(%s)֮��Լ�Զ������", 
                me->query("marry_name"),
                me->query("marry"),
                me->name(1),
                me->query("id")));
		me->delete("marry");
        me->add("divorced",1);
        me->delete("marry_name");
        destruct(owner);
        destruct(spouse);
        return 1;
    }			 	
		
	file = DATA_DIR + "login/" + name_c[0..0] + "/" + name_c +"/" +  name_c + SAVE_EXTENSION;

//	tell_object(me,"file is "+ file);
	
	info = stat(file);
	duration = time()- info[1];
	
	if (duration<0){
		tell_object(me,"Ŀǰϵͳʱ�����ң��������ִ�С�\n");
		destruct(spouse);
		destruct(owner);
		return 1;
	}

//	if (duration < 10) {	
	if (duration < 5184000) {
		message_vision("ý��˵����ѽ���Ź���"+ chinese_number(duration/86400)+"����Ͱ���ס�����ٵ���"
		+ chinese_number(60 - duration/86400)+"�쿴���ɣ�˵������������˻�������ġ�\n",me);	
		destruct(spouse);
		destruct(owner);
		return 1;
	}
			
	message_vision("ý��ҡҡͷ˵��"+spouse->name()+"��Ȼ��ô���Ķ����㲻�ܣ��ҾͰ����ɡ�\n",me);
	CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)ʧ�ٶ��գ�%s(%s)��������Լ�����ٻ顢Ů�ټ޻�����ɣ���", 
                spouse->name(1),
                spouse->query("id"),
                me->name(1),
                me->query("id")));
	
	me->delete("marry");
    me->add("divorced",1);
    me->delete("marry_name");	
	
	spouse->delete("marry");
	spouse->add("divorced",1);
	spouse->delete("marry_name");
	
	me->save();
	spouse->save();
	
	destruct(owner);
	destruct(spouse);
	
	return 1;	
}


int do_marry(string arg) //there is a marry emote, ruined all the messages.
{
    object obj, me;
    object ob;
    int i;
    string myclass,otherclass;
    me = this_player();
    if( me->query("marry"))
        write("���Ѿ��ͱ����л�Լ�˰�?���ﲻ�����ػ�ġ�\n");
    else if (me->query("jiebai"))
    	write("���Ѿ����˽�ݹ��ˣ���ο��йؽ��ͽ�ݵİ����ļ���\n");
    else if(!arg || !objectp(obj = present(arg, environment(me))))
        write("�����˭�޽���Ե��\n");
    else if( obj->query("marry"))
        write("��Ķ����Ѿ��ͱ����л�Լ�˰�?���ﲻ�����ػ�ġ�\n");
    else if (obj->query("jiebai"))
    	write("��Ķ����Ѿ����˽�ݹ��ˣ���ο��йؽ��ͽ�ݵİ����ļ���\n");
    else if((int)me->query("age")<14 && (string)me->query("gender")=="����" ||
            (int)me->query("age")<12 && (string)me->query("gender")=="Ů��")
        write("��̫С������ô��������\n");  
    else if((myclass = me->query("class")) == "bonze" || myclass == "wudang" ||
            myclass == "lama" || myclass == "shaolin" || myclass == "taoist" ||
            (otherclass = obj->query("class")) == "bonze" || myclass == "wudang" ||
            otherclass == "lama" || otherclass == "shaolin" || myclass == "taoist")
        write("�������ǲ����Խ��ġ�\n"); 
    else if( !living(obj) )
        write(obj->name() + "�Ѿ��޷�����޽���Ե�ˡ�\n");  
    else if(obj==me)
        write("������������\n");
    else if(!userp(obj))
        write("��ֻ�ɺ���ҽ�顣\n");
    else if((string)obj->query("gender")== (string)me->query("gender")) {    	
    	ccommand("tong");
        write("���䣿����ƺ��ڷ����ﻹ�в�ͨ��\n");  
    } else if( userp(obj) && !obj->query_temp(me->query("id") + "m"))
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
    }
    else
    {
        me->set("marry",obj->query("id"));
        me->set("marry_name",obj->query("name"));
        obj->set("marry",me->query("id"));
        obj->set("marry_name",me->query("name"));
        obj->delete_temp(me->query("id")+"m");
        
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
    else if (me->query("jiebai"))	write("�뵽��Դͤȥ������塣\n");
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
        couple_ob->delete_temp(me->query("id")+"d");
        
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
        message_vision(YEL" $N �� $n �Ļ�Լ�Ѿ���¼�ڰ���\n"NOR,
                       obj, me);
    }
    return 1;
}