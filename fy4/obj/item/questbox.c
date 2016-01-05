// questbox.c By Silencer@fy2005 workgroup, Nov.2005
/*
	������רΪ�洢�ѣգ�����Ʒ��������Ʒ����ʵ����ڣ�ֻ�����ڣѣ���������
	�������������ļ����������Ŀ¼�У�Ϊ��ʡ��д���̣�
		�����������ڣ�������ӣΣУô�ȡ��������ʱ��ͬʱ���ٸ��ļ�
		д���������ڣ��������������������������˳�ʱ��д�󽫽�������ʵ������
	���κ�����£��ļ�������ֻ����һ�����ڡ�
	��Ŀ�����ڣ�
	����������󲿷���Ҫ���߱�����������Ʒ����Ҫ	
	��������ʡϵͳ�д�����ν�����ͣ����������Դ
	���ֻ���ǵ������䣬û���κ���Ҫ�ٱ��ֳ������ߡ�
	
	���ܺ����
	�������������е���Ʒֻ��������	���٣��������Ʒ�ڲ�ͬ��Ҽ����ͨ����һ���Ǽ�����
	������������ʮ�ֱ����ɿ����ߵȼ�����ҿ���͵ȼ�����Ҵ����������������Ʒ��			

*/
#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

int do_qput(string arg);
int do_qqput(object me, object obj);
int do_qsave();
varargs int do_qqsave(object me);
int do_qdiscard(string arg); 
varargs int do_qqdiscard(string arg, object me, int silent);

string replace_color(string arg);

mapping items=([]);
/* ��ʽΪ��
items = ([
	������	5
	�����ӣ� 1
]);	
*/

void create() {
	set_name("�������", ({ "treasure box","treasurebox",}) );
	set("long","
һ����˸�ŵ�����ɫ�ĺ��ӣ��������ɷ����д���ĸ�����
���������ɡ������Ƿ�����ר�����������������������Ʒ
�ı��С�������ʹ�÷�����ο�����𡡣�����е���
������ƪ����������е���Ʒ��ֻ�����ڣѣ���������
������ȡ����

�����֧������ָ�
������qlook �쿴���������Ʒ�б�
������qput <ĳ��Ӣ�ģ��> ����Ʒ�����������
������qdiscard <ĳ����������> �������ĳ�����ö���
������qdiscard num <ĳ����������> ������У����������ĳ�����ö���
������qdiscard all �����������е���Ʒ
������qsave������н�����ϵͳ�洢����

��������˴���ʹ��
������qreturn �Զ���Ѱ��н�����������
������qreturn <ĳ��������> ָ������ĳ���������Ʒ

\n");
	set("unit", "��");
	set("lore", 1);
	set("quest_box",1);
	set("no_split",1);
	set("no_drop", 1);
}


void init() {
	object ob;

	if(this_player() && environment()==this_player() ) {
		set("owner_id",this_player()->query("id"));
		set_name( this_player()->name(1) + "���������", ({ "treasure box","treasurebox" }) );
		add_action("do_qput", "qput");
		add_action("do_qlook", "qlook");
		add_action("do_qdiscard", "qdiscard");
		add_action("do_qsave", "qsave");
	}
}

mapping item_list(){
	return items;
}

string query_save_file() {
	string id;
	if(!stringp(id = query("owner_id"))) return 0;
	return sprintf(DATA_DIR "user/%c/%s/treasurebox", id[0],id);
}

int do_qput(string arg) {
	
	object *inv, me, obj, obj2;
	int amount;
	string item;
	
	if (!arg)
		return notify_fail("��Ҫ������������ʲô������\n");
		
	me = this_player();
	inv = all_inventory(me);
	
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( obj->query("no_drop"))	// Enough? Qput == Burn I guess
			return notify_fail("�����������ܷ�����������\n");
		if (obj->query("dynamic_quest"))
			return notify_fail("TASK�Ž�ȥ����ô������\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ��š�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û��������" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_qqput(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			seteuid(getuid());
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			obj2->set_name(obj->query("name"),obj->parse_command_id_list());
			obj2->set("long",obj->query("long"));
			obj2->set("unit",obj->query("unit"));
			if(!do_qqput(me, obj2)) {
				obj->set_amount( (int)obj->query_amount() + amount );
				return 0;
			}
			if (obj2) destruct(obj2);
			return 1;
		}
	} else {
		if(!objectp(obj = present(arg, me)))
			return notify_fail("������û������������\n");
		return do_qqput(me, obj);
	}
	
}


int do_qqput(object me, object obj)
{
	string prep,*dir, name;
	int container_size, amount,index;
	
    if(obj->query("no_drop") || obj->query("no_get")||obj->query("lore"))
    	return notify_fail("�㲻�ܽ�����ŵ���������С�\n");
	
	if (obj->query("dynamic_quest"))
		return notify_fail("TASK�Ž�ȥ�㻹��ô������\n");
			
	if (obj == this_object())
		return notify_fail("�ŵ��Լ����棿���²��С�\n");
	
	dir = keys(items);
	name = obj->query("name");	// We use Chinese Name to index Items.
	index = member_array(name, dir);
		
	container_size = 50;
	
	//������������еĶ�������ʹ����
	if ( index == -1 && sizeof(items)>= container_size)	
		return notify_fail( "��������������ֻ�ܷ�" + chinese_number(container_size)+"����Ʒ��\n");
	
	prep = "�Ž������������";

	message_vision( sprintf("$N��һ%s%s%s��\n",
			obj->query("unit"), obj->name(), prep),
			me );
	amount = obj->query_amount()>0? obj->query_amount(): 1;
			
	if (index != -1) {
		items[dir[index]] += amount;
	} else
		items[name]= amount;
	
	destruct(obj);
	return 1;
}

int do_qlook(){
	int i,j,k,extra,num;
	string *list,outstring;

	if (this_object()->query("timer/op") + 4 > time()) {
		write("Ϊ��ʡϵͳ��Դ��������������������������ȴ������ӡ�\n");
		return 1;
	}		
	this_object()->set("timer/op", time());
			
	num = sizeof(items);
	
	write(WHT"\t  " + name()+ "�е���Ʒ�嵥��"+num+"/50��\n"NOR);
    write(HIR BLK"����������������������������������������������������������������\n"NOR);

    if (!num)	write (HIR "�����տ���Ҳ����������������\n"NOR);
    else
    {
		list = keys(items);
		for(i=0; i<num; i++){
			k = 0;
			extra = 0;
			for(j=0; j<strlen(list[i]); j++) {
				if(list[i][j] == ESC[0]) {
					k = 1;	
				}
				if(k == 1) {
					extra++;
				}
				if(list[i][j] == 'm') {
					k = 0;	
				}
			}					      			
        	if (i%2==0){
        		outstring = sprintf("%-*s %5d��", 
        					22+extra,
        					list[i],
        					items[list[i]]);
        		if (i==num-1)
        			outstring +="\n";
        	}			
        	else
        		outstring = sprintf("%-*s %5d\n", 
        					22+extra,
        					list[i],
        					items[list[i]]);
        	write(outstring);
        }
    }
    write(HIR BLK"����������������������������������������������������������������\n"NOR);
    
	return 1;
}

int do_qsave(){
	object me;
	me = this_player();	
	do_qqsave(me);
	return 1;
}

varargs int do_qqsave(object me){
	
	int num;
	save();
	tell_object(me,"���������ϵͳ�Զ����棬��Ҫʱ�������ĸ��Ϲ�ѩ����ȡ����\n");
	num = sizeof(items);
	log_file( "QBOX_LOG", sprintf("(%s) %s �洢�ɹ���%d����\n", 
			ctime(time()),
			me->query("id"),
			num)
			); 
	destruct(this_object());
	return 1;
}

// DON"T CALL THIS FUCTION FROM OUTSIDE
// it can't garantee item will be deleted.
int do_qdiscard(string arg) {
	object me;
	me = this_player();
	
	if (this_object()->query("timer/op") + 2> time()) {
		write("Ϊ��ʡϵͳ��Դ��������������������������ȴ������ӡ�\n");
		return 1;
	}
	this_object()->set("timer/op", time());
	
	do_qqdiscard(arg, me, 0);	
	return 1;
}

// when call this from outside, make sure the item exists yourself!
varargs int do_qqdiscard(string arg, object me, int silent) {
	int num, amount, amount1, index, i;
	string item,*dir;
	
	if(!arg){
		tell_object(me,"��Ҫ������һ����Ʒ��\n");
		return 0;
	}
	
	if (arg == "all") {
		items = ([]);
		tell_object(me,"�������������ϡ�������������Ʒ��ɾ����\n");
		return 1;
	}
			
	if(sscanf(arg, "%d %s", amount1, item)==2)
		arg = item;
	else
		amount1 = 1;
	
	if (amount1<=0){
		tell_object(me,"��Ҫ�����Ķ�����Ŀ������������\n");
		return 1;
	}
			
	arg = replace_color(arg);
	num = sizeof(items);
	dir = keys(items);
	index = member_array(arg, dir);
	if (index == -1) {		// ��һ������ɫ��ƥ��
		for (i= 0; i<num; i++) {
			if ( arg == "/feature/nada"->ngstr(dir[i])) {
				index = i;
				break;
			}
		}
	}
	
	if (index == -1) {
		tell_object(me,"���������û������Ҫ���ٵ������\n");
		return 0;
	}
	
	amount = items[dir[index]];
	// if amount1 is bigger.. assume ppl wants to delete all
	if (amount > amount1)	{
		items[dir[index]]= amount-amount1;
			tell_object(me,"��������е�"+arg + "������"+chinese_number(amount1)+"����λ��\n");
	}
	else
	{ 
		num --;
		if (sizeof(items) == 1){
			items = ([]);
			if (!silent) 	
				tell_object(me,"���������п��ˡ�\n");
		} else 
			map_delete(items, dir[index]);
			if (!silent)	
				tell_object(me,"������������е�"+arg+"��������ˡ�\n");
	}
	return 1;
}

string replace_color(string ccolor){
		ccolor = replace_string(ccolor, "$BLK$", "[0;30m");
        ccolor = replace_string(ccolor, "$RED$", "[0;31m");
        ccolor = replace_string(ccolor, "$GRN$", "[0;32m");
        ccolor = replace_string(ccolor, "$YEL$", "[0;33m");
        ccolor = replace_string(ccolor, "$BLU$", "[0;34m");
        ccolor = replace_string(ccolor, "$MAG$", "[0;35m");
        ccolor = replace_string(ccolor, "$CYN$", "[0;36m");
        ccolor = replace_string(ccolor, "$WHT$", "[0;37m");
        ccolor = replace_string(ccolor, "$HIR$", "[1;31m");
        ccolor = replace_string(ccolor, "$HIG$", "[1;32m");
        ccolor = replace_string(ccolor, "$HIY$", "[1;33m");
        ccolor = replace_string(ccolor, "$HIB$", "[1;34m");
        ccolor = replace_string(ccolor, "$HIM$", "[1;35m");
        ccolor = replace_string(ccolor, "$HIC$", "[1;36m");
        ccolor = replace_string(ccolor, "$HIW$", "[1;37m");
        ccolor = replace_string(ccolor, "$NOR$", "[2;37;0m");
    return ccolor;
}    
