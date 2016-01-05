// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
    	set_name("��Դͤ��", ({ "taoyuan tingzhu","tingzhu" }) );
    	set("title", HIR"��Դ������ ����������"NOR);
    	set("no_arrest",1);
    	set("gender", "����" );
    	set("age", 143);
    	set("long", "һλ���뾡�׵����ߣ���ü��Ŀ��΢Ц�ؿ����㡣\n");
    	set("combat_exp", 10000000);
    	set("attitude", "friendly");
    	set("inquiry", ([
        	"����" : 	"������Դ���壬����ǧ�ţ���Ϊ�Ϸ���Ľ�����ܼ�֤�����д��������£�������ա�",
        	"jieyi" : 	"������Դ���壬����ǧ�ţ���Ϊ�Ϸ���Ľ�����ܼ�֤�����д��������£�������ա�",
       		"����":		"�����ֵ��������������ȿ�Ҫ��˼���а������۶���֮�٣��������޿���أ�������������Ϊ�",
        	"juejiao":	"�����ֵ��������������ȿ�Ҫ��˼���а������۶���֮�٣��������޿���أ�������������Ϊ�",
       	]) );
        
    	set_skill("dodge", 500);
    	set_skill("unarmed", 300);
    	setup();
    
    	carry_object("/obj/armor/cloth")->wear();
}


void init()
{
    	add_action("do_marry", ({"jieyi", "jiebai"}) );
    	add_action("do_unmarry", "juejiao");	
    	add_action("do_desert", "betray");	
}


int do_desert(string arg){
	
	object me;
	string name_c,file;
	object spouse,owner;
	int duration,flag;
	mixed info;
	
	seteuid(getuid());
	
	me = this_player();
	
    if (!stringp(name_c = me->query("jiebai")))
    	return notify_fail("��û���˽�ݰ�����ʲô�ң�\n");

	if (!arg)
		return notify_fail("��Ҫ��˭������\n");
		
	if (arg != name_c)
		return notify_fail("��Դͤ��˵���ǲ�����Ľ���ֵܽ��ðɣ�\n");
		
	if (objectp(spouse = find_player(name_c)))
		return notify_fail(spouse->name(1)+"����������ô��ֱ�������˶Ͼ����ˡ�\n");
		
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
		message_vision(CYN"��Դͤ��̾�˿���˵�������ĺ��ӣ��˹������������ˣ��Ϸ�Ͱ����ɡ�\n"NOR, this_object());
        CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)�����������%s(%s)֮����Զ������", 
                me->query("marry_name"),
                me->query("marry"),
                me->name(1),
                me->query("id")));
		me->delete("marry");
		me->delete("jiebai");
        me->add("divorced",1);
        me->delete("marry_name");
        return 1;
     }
	
	// �������� s-f ����Loginһ����ͬid��
	if (spouse->query("marry")!= me->query("id")
		 && spouse->query("marry_name")!= me->name(1)){
		 message_vision(CYN"��Դͤ��̾�˿���˵�������ĺ��ӣ������޳����������ü����������٣��Ϸ�Ͱ����ɡ�\n"NOR, this_object());
        CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)��Ȼ���٣��ѷǽ���֮�ˣ���%s(%s)֮����Զ������", 
                me->query("marry_name"),
                me->query("marry"),
                me->name(1),
                me->query("id")));
		me->delete("marry");
		me->delete("jiebai");
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
		message_vision("��Դͤ����Ȼ����������Դ�����壬����Ϊ�����ε����壬����Ź���"+ chinese_number(duration/86400)+"����ж��ģ��������գ�
�ٵ���"+ chinese_number(60 - duration/86400)+"�쿴���ɣ�˵��������������û�������ġ�\n",me);	
		destruct(spouse);
		destruct(owner);
		return 1;
	}
			
	message_vision("��Դͤ��ҡҡͷ˵��"+spouse->name()+"��Ȼ�鱡��ˣ����ֶ�ȥ�����Ϸ�Ͱ����ɡ�\n",me);
	CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)ʧ�ٶ��գ�%s(%s)������������Լ������������ɣ���", 
                spouse->name(1),
                spouse->query("id"),
                me->name(1),
                me->query("id")));
	
	me->delete("marry");
    me->add("divorced",1);
    me->delete("marry_name");
    me->delete("jiebai");	
	
	spouse->delete("marry");
	spouse->add("divorced",1);
	spouse->delete("marry_name");
	spouse->delete("jiebai");
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
    string myclass,otherclass,word1;
    string myname, hisname;
    me = this_player();
    
    if (!arg){
    	write("��Ҫ��˭��ݣ�\n");
    	return 1;
    }
    	
    if( me->query("marry") || me->query("jiebai"))
        write("���Ѿ��ͱ�����Լ�˰ɣ���Ҫ�����Ķ����ˡ�\n");
        
    else if(!arg || !objectp(obj = present(arg, environment(me))))
        write("�����˭��ݣ�\n");
        
    else if (obj->query("jiebai"))
    	write("�Է��Ѿ������˽�ݹ��ˡ�\n");
              
    else if( obj->query("marry"))
        write("��Ķ����Ѿ����������ˡ�\n");
        
    else if((int)me->query("age")<14 && (string)me->query("gender")=="����" ||
            (int)me->query("age")<12 && (string)me->query("gender")=="Ů��")
        write("������̫С���Ķ����ý�ݵĺ����أ��С�14��Ů��12����\n");  

/*    else if((myclass = me->query("class")) == "bonze" || myclass == "wudang" ||
            myclass == "lama" || myclass == "shaolin" || myclass == "taoist" ||
            (otherclass = obj->query("class")) == "bonze" || myclass == "wudang" ||
            otherclass == "lama" || otherclass == "shaolin" || myclass == "taoist")
        write("�������ǲ����Խ�顣\n"); */
    else if( !living(obj) )
        write(obj->name() + "�Ѿ��޷������ݡ�\n");  
        
    else if(obj==me)
        write("������������\n");
        
    else if(!userp(obj))
        write("��ֻ�ɺ���ҽ�ݡ�\n");
/*   else if((string)obj->query("gender")== (string)me->query("gender")) {    	
    	ccommand("tong");
        write("���䣿����ƺ��ڷ����ﻹ�в�ͨ��\n");  
    }*/ 
    else if( userp(obj) && !obj->query_temp(me->query("id") + "j"))
    {
        myname = me->name(1);
        hisname = obj->name(1);
        
        if (me->query("gender")=="����" && obj->query("gender")=="����") 
        	word1 = "�ֵ�";
        else if (me->query("gender") == "Ů��" && obj->query("gender") == "Ů��")
        	word1 = "����";
        else {
        	if (me->query("mud_age") < obj->query("mud_age"))
        		word1 = "���";
        	else
	        		word1 = "����";
        }        	
        
        message_vision(CYN"$N����Դͤ������һ����֣�ص�����"+ myname+"��"+ hisname +"��ʶ����������ͶԵ������"+word1+"��
�����������Ӵ�"+word1+"��ƣ�������������֤�ˣ�\n"NOR,me);       
        me->set_temp(obj->query("id") + "j",1);
        tell_object(obj, "��Դͤ��΢΢һЦ�������ʵ���"+myname+"����������������Ϊ����"+word1+"����������Σ�
�����Ը�⣬����Ҳ��"+myname+"("+(string)me->query("id")+")"+ "��һ�� jieyi ָ�\n");        
    }
    else
    {
        me->set("marry",obj->query("id"));
        me->set("marry_name",obj->query("name"));
        me->set("jiebai",obj->query("id"));
        obj->delete_temp(me->query("id")+"j");
        
        obj->set("jiebai",me->query("id"));
        obj->set("marry",me->query("id"));
        obj->set("marry_name",me->query("name"));
        message_vision(HIC"��Դͤ������������ף���ɫ��Ȼ���ڳ��������������񣬰������ݣ��������дʣ�
Ȼ��ת��ʾ�����ߵ�ݽ��塣\n"NOR,obj, me);
        
        message_vision(HIC"\n����"+me->name(1)+"��"+ obj->name(1)+"����Ϊ�㣬�ѪΪ�ˣ���Ϊ�˰�֮������\n\n"NOR,obj, me);
        CHANNEL_D->do_sys_channel("info",sprintf(
                "%s(%s)��%s(%s)��%s����Դͤ��������", 
                me->name(1),me->query("id"), obj->name(1), obj->query("id"),
                NATURE_D->game_time()));
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
    if (!me->query("jiebai"))  write("��δ�����˽�ݡ�\n");
    else if(!objectp(couple_ob =
                present(target=(string)me->query("jiebai"), environment(me))))
        write("��Ľ���ֵ�/���ò��������\n");
        
    else if( userp(couple_ob) && !couple_ob->query_temp(me->query("id")+"dj"))
    {
        message_vision(WHT "\n$N��˻����һ����������ǰ��˺�£���$n˵�������ҽ����Ѷ���������ʹ��˶��˰ɣ�\n\n"NOR, me, couple_ob);           
        me->set_temp(couple_ob->query("id")+"dj",1);
        tell_object(couple_ob,  "�����Ը����Է�����������Ҳ" + "��һ�� juejiao ָ�\n"NOR);        
    } else { 
        me->delete("marry");
        me->delete("jiebai");
        couple_ob->delete("marry");
        couple_ob->delete("jiebai");
        couple_ob->delete_temp(me->query("id")+"dj");
        me->add("divorced",1);
        couple_ob->add("divorced",1);
        message_vision(WHT " $N �� $n ���۶��壬�Ӵ˻�����ɣ�\n\n"NOR,couple_ob, me);
        CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)��%s(%s)���۶��壬�Ӵ˸���������������ɣ�",couple_ob->name(1),
                couple_ob->query("id"),me->name(1),me->query("id")));
    }
    return 1;
}
