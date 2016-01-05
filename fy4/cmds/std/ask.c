// ask.c -- by silencer@fy4 9/28/2002

#include <ansi.h>
inherit F_CLEAN_UP;

string in_this_room(object me,string arg);
string look_for_company(object me, object room, string information, int n);
string check_being(object room, string arg, object me);
string *msg_dunno = ({
	"$n��$N˵������....����������������Լ���\n",
	"$n��$N˵�����Բ�����������㻹��ȥ�ʱ��˰ɡ�\n",
	"$n�����ʼ磬����ϧ�ض�$N˵���޿ɷ�棡\n",
	"$n��$N˵������....������Ĵ���Ҫ�ú���һ�롣\n",
	"$n�����۾�����$N����ô�򵥵����ⶼҪ����\n",
	"$nҡ��ҡͷ��$N˵���Ҳ�֪����\n",
	"$nҡ��ҡͷ��$N˵��û��˵����\n",
	"$n������Ƭ�̶�$N˵�������е�ӡ�󣬲�����ôҲ�벻�����ˡ�\n",
	"$n�ɻ�ؿ���$N,��Ȼ��$N������һ����֪��\n",
});


int main(object me, string arg)
{
	string dest, topic, msg , file_msg, char_name;
	string *chat_msg;
	object ob;
	int i;
	mapping inquiry;

	
	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲ���£�\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("����û������ˡ�\n");

	if( !ob->is_character() ) {
		message_vision("$N����$n��������....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N��$n�����йء�" + topic + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}

	if (me->query_temp("inquiry_time")+1>time()) {
		message_vision("$N��$n˵����������̫������������������⡣\n"NOR,ob,me);
		return 1;
	}
	
	me->set_temp("inquiry_time",time());
	
	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		tell_object(me,"���Ǻ���Ȼ�ģ�"+ob->name()+"���ڵ�״��û�а취�����κδ𸲡�\n",
			me, ob);
		return 1;
	}

	if (ob->query("NO_ASK"))
	{
		tell_object(me,ob->query("NO_ASK"));
		return 1;
	}

//	ask for name.
	if(topic == "name" || topic == ob->query("id") || topic == ob->query("name")){
		message_vision("$n˵����$n�����ң��Ҿ���$n����ʲô��ô��\n",me,ob);
		return 1;
	}


//	ask for spouse
        if ( ob->query("marry"))
        if ( topic == ob->query("marry") || topic == ob->query("marry_name")) {
        	message_vision("$n˵����"+ob->query("marry_name")+"��"+(ob->query("gender") == "Ů��" ? "����":"����")+"����ʲô��ô��\n",me,ob);
        	return 1;
       	}


//	ask for chat_chance message.
	if(topic == "here"){
		chat_msg = ob->query("chat_msg");
		i = random(sizeof(chat_msg));
		if(sizeof(chat_msg) > 0) {
			if (stringp(chat_msg[i])){
				message_vision(chat_msg[i], me, ob);
				
			} else { 
				message_vision("$n˵������....��������������һ���ȣ�\n", me, ob);
			}
		} else {
			message_vision("$n˵�����ţ����������ʲô���أ�\n",me,ob);
		}	
		return 1;
	}

//	hijack the old "leave" msg here
	if (topic == "leave" && me->is_apprentice_of(ob))
	{
		message_vision(CYN"$N������õ�����Ҫ���ʸ�֦�ˡ����˸���־��������ǿ���������Ÿ��ɶ���
�Լ����������ķ��ţ�����ʦ�ţ�ԭ�����书�ؼ�����û�����ˣ�������ʦ��
Ҳ���ᾡ�ľ����ؽ��㣨��ʦһ����ѧ20�����ܣ����ú�����ɣ������ž�û��
��ͷ·�ˡ�\n"NOR, ob);
		return 1;	
	}
	
	if (topic == "��ʦ" || topic == "betray" ) {
		if (me->is_apprentice_of(ob))	{
			message_vision("$N˵���˸���־������Ҫ�ߣ��Ҳ���ǿ���Ժ�Ͳ�Ҫ�ٻ����ˡ�\n",ob);
			ob->betray_action(me);
			me->set_temp("marks/apprentice_others",1);
		
		} else
			message_vision("$N˵�����ֲ����ҵ�ͽ�����������Һθɣ�\n",ob);
		return 1;
	}
	
//	check for specified msg (in NPC) or general msg	(under that area/NPC directory)
	if( msg = ob->query("inquiry/" + topic)) {
		if( stringp(msg)) {
			if (msg[0..5]=="action")  // ������������һ��û�С�ĳĳ˵����msg�����msg������action��ͷ��
				message_vision(CYN""+msg[6..sizeof(msg)-1]+"\n"NOR,ob);
			else 
				message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
		}
		return 1;
	}	
	
		
	if( stringp(ob->query_inquiry_msg(topic))) {
		message_vision( CYN "$N˵����" + ob->query_inquiry_msg(topic) + "\n" NOR, ob);
		return 1;
	}

//	check for nearby characters --- NPC is aware of his environment

	if (char_name= in_this_room(me,topic)) {
		message_vision(CYN "$N"+CYN"˵����"+char_name+CYN"����������ǰô��\n"NOR,ob);
		return 1;
	}
	
	if (char_name = look_for_company(me, environment(ob),topic, 3)) {
		message_vision(CYN "$N"+CYN"˵�����ţ�����������"+char_name+CYN"��Ӧ�þ��������\n"NOR,ob);
		return 1;
	}
	
//	check for general replies	
	if (msg = ob->query("inquiry/" + "*")){
		if (msg[0..5]=="action")  // ������������һ��û�С�ĳĳ˵����msg�����msg������action��ͷ��
				message_vision(CYN""+msg[6..sizeof(msg)-1]+"\n"NOR,ob);
			else 
				message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
	} else {
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
	}
	return 1;

}

int help(object me)
{
   write( @HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	ask <ĳ��> about <ĳ��>    ѯ��ĳ��ĳ����  
		ask <ĳ��> about <ĳ��>    ѯ��ĳ�˵����
		ask <ĳ��> about here      ѯ��ĳ�˵�������Ϣ[0m
[0;1;37m����������������������������������������������������������������[0m   

������һ���µ�NPCʱ�������ʹ��
ask <ĳ��> about here ����֪�����ճ�������Ϣ��ƽʱ�����Ķ�����

���������NPC�ı�����Ϥ�Ļ���������
ask <ĳ��> about <ĳ��> ����֪����������/������������ۡ�

�����֪��ĳ�˾��ڸ�������һʱ�Ҳ�����������
ask <ĳ��> about <ĳ��>   ���NPC����������ˣ������һ����ʾ��

���ָ���ڽ���ʱ����Ҫ��������ⶼ����ѯ��NPCĳ���ؼ��������Ʒ
�������������ģ��ؼ�������Ʒ�����־�Ҫ����۲����Ƿ����񣬶��й�
����С˵�Ƿ���Ϥ�ˡ�
[0;1;37m����������������������������������������������������������������[0m
HELP
   );
   return 1;
}


string in_this_room(object me,string arg) {
	object *inv;
	int i;
	
	inv=all_inventory(environment(me));
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("id")== arg || inv[i]->query("name")== arg) 
			return inv[i]->query("name");
	}
	return 0;
}


string look_for_company(object me, object room, string information, int n) {

        object *inv, next_room;
	int i;	
	mapping exits;
	string *dirs, dest, id_name;
        
        if( mapp(exits = room->query("exits")) ) 
	{
		dirs=keys(exits);
		for(i=0;i<sizeof(dirs);i++)
		{
			dest=room->query("exits/"+dirs[i]);
			if(!next_room=find_object(dest))
				next_room=load_object(dest);
			if (!objectp(next_room)) continue;
			if (next_room==environment(me)) continue;
			if (next_room->query("summoned")) continue;
			if (!n) continue;
			if (id_name=check_being(next_room, information, me)) {
				room->delete("summoned");
				next_room->delete("summoned");
				return id_name;
			}	
			if (id_name=look_for_company(me,next_room,information,n-1)) {
				room->delete("summoned");
				next_room->delete("summoned");
				return id_name;
			}
		}
	}
	room->delete("summoned");
	return 0;
}


string check_being(object room, string arg, object me) {
	object *inv;
	int i;
//	tell_object(me,"room is"+ (string)room->query("short")+"\n");
	room->set("summoned",1);
	inv=all_inventory(room);
	if (!sizeof(inv)) return 0;
	for(i=0;i<sizeof(inv);i++){
		if (!inv[i]->is_character()) continue;
		if (inv[i]->query("id")== arg || inv[i]->query("name")==arg) {
			return 	inv[i]->query("name");
		}
	}
	return 0;
}