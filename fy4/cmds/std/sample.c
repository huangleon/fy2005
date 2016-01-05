// buy.c
#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string *name, item, targ;
	object ob, owner, buyer;
	int i,num;
	mapping goods;
	
	if( me->is_busy())
		return notify_fail("����һ��������û����ɣ����ܲ쿴��Ʒ��\n");
		
	if( !arg || sscanf(arg, "%d from %s", num, targ)!=2 )
		return notify_fail("ָ���ʽ��sample <��Ʒ���к�> from <ĳ��>\n");

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("��Ҫ��˭�Ƕ��쿴��Ʒ��\n");

	if (!(owner->is_vendor())) 
		return notify_fail("���˲���������û�����ɲ쿴��\n");

	// ������������һ���ɵ��õ��жϣ�����˵����������ϲ������ˣ����鲻�ò��������ˡ�������
	if (!owner->legit_buyer(me))
		return notify_fail(owner->name()+"��Ը�����������ס�\n");
	
	
	if( !mapp(goods = owner->query("vendor_goods")) ) 
		return notify_fail("�����û������\n");
	
	name = keys(goods);
	if(!sizeof(name))
		return notify_fail("����Ķ���ȫ�����ˡ�\n");
	
	if ( num > sizeof(name) || num <= 0 )
		return notify_fail("û�������ŵ���Ʒ��\n");
	
	if (me->query_temp("timer/sample")+2 > time())
		return notify_fail(owner->name()+"��Ц�������͹��Ժ����Ͼ����к�����\n");
	me->set_temp("timer/sample",time());
	
	num = num - 1;
		
	ob = new (name[num]);
	if (!objectp(ob))
		return notify_fail("�������������˵����⣬��㱨����ʦ�ɡ�\n");	
	
	buyer = this_player();
	buyer->set_temp("checking_goods",1);
	"/cmds/std/look"->look_item(buyer,ob);
	buyer->delete_temp("checking_goods");	
	destruct(ob);
	
		
	return 1;
	
	
}

int help(object me)
{
   write( @HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	sample <ĳ��Ʒ���> from <someone>[0m
[0;1;37m����������������������������������������������������������������[0m   

��һָ��������Դ��̷�����쿴�������Ϣ��

�ǲ��ǻ���Ϊ�����ͻ����赽����ʲô�ô����
�ǲ��ǻ��������Ƿ�Ӧ��Ͷ�ʹ���һ���������Ʒ��
�����������ڹ���ǰ�쿴�������Ϣ��

���У���Ʒ���Ϊ��list����ʱ����Ʒǰ��ı�š�

[0;1;37m����������������������������������������������������������������[0m   

HELP
   );
   return 1;
}
