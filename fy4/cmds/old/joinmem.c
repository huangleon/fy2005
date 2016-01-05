// memebership key generator
#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{

 int bday,mterm;
 string mid,mmud, mlevel;
 mapping membership;
 string mkey;
 if( !arg ) 
  return notify_fail("ָ���ʽ��joinmem <��Ա�������봮> \n");
 if((int)me->query("mem_last_try") + 3600 > time())
  return notify_fail("�����ϴ��������Ϊ�˱������ƻ�Ա��Ȩ�棬��һСʱ�����������봮��\n");  
 mkey = bicrypt(arg);
 if(sscanf(mkey,"%s@%s-%d-%d-%s",mid,mmud,bday,mterm,mlevel) != 5) {
  me->set("mem_last_try",time()); 
  return notify_fail("�Բ������Ļ�Ա�������봮��"+arg+"�����ԣ�
�������������һСʱ�����ԣ�������EMAIL��member@fengyun.com\n");
 }
//See if this string is for this user
 if((string)mid != (string)me->query("id"))
  return notify_fail("�Բ������Ļ�Ա�������봮��"+arg+"�����ԣ�
�������������һСʱ�����ԣ�������EMAIL��member@fengyun.com\n");
 if((string)mmud != INTERMUD_MUD_NAME)
  return notify_fail("�Բ������Ļ�Ա�������봮��"+arg+"�����ԣ�
�������������һСʱ�����ԣ�������EMAIL��member@fengyun.com\n");
 if((int)mterm < (int)me->query("membership/mterm"))
  return notify_fail("�Բ������Ļ�Ա�������봮��"+arg+"���Ѿ������ˡ�\n");

// Ok, everything seems fine. now let's set his/her status
 me->set("membership/level",mlevel);
 me->set("membership/mterm",mterm+1);
 me->set("membership/start",time());
 write("��ϲ����Ϊ���ƻ����ʽ��Ա�����ڻ�ԱȨ�棬��ο����Ƽ�ҳ��\n");
 me->save();
 return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��membership <[]|gold|silver|bronze>    

���ָ���ṩ�����ĳһ�������ϸ˵���ļ������ǲ�ָ�����⣬���ṩ���й�
������ļ���
HELP
	);
	return 1;
}

