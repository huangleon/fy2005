// memebership key generator
#include <ansi.h>
#include <mudlib.h>
#include <membership.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{

 int bday,mterm;
 mapping membership;
 string mkey;
 string mlevel;
 mixed *local;
 // If no argument, let's display this player's membership status
 if( !arg ) {
  write("\n\n");	
  if(mapp(membership=me->query("membership")))  {
   if(membership["start"]+EXP_PERIOD < time()) {
    write("��ķ��ƻ�Ա���Ѿ������ˡ��������������Ļ������룺help membership\n"); 
    return 1;
   } else {
// This is where to show all the member status
    if(membership["level"] == "gold") mlevel="��"; 
    if(membership["level"] == "silver") mlevel="��"; 
    if(membership["level"] == "bronze") mlevel="ͭ"; 
    write(" �������Ƿ���"+mlevel+"����"+chinese_number(membership["mterm"])+
     "�ڻ�Ա��\n");
    local= localtime(membership["start"]+EXP_PERIOD);
    write(" ���"+mlevel+"������"+chinese_number(local[5])+"��"+
     chinese_number(local[4]+1)+"��"+chinese_number(local[3])+"�Ź��ڡ�\n");
    write("\n");
   }
  return 1; 
  } else 
  return notify_fail("�����ڲ����Ƿ��ƻ�Ա�������������Ļ������룺help membership\n");
 }
 bday = (int)me->query("birthday")%10000;
 mterm = (int)me->query("membership/mterm");
 mkey = (string)me->query("id")+"@"+INTERMUD_MUD_NAME+" "+sprintf("%d-%d-",bday,mterm);
 switch(arg) {
  case "gold" :
   mkey += "gold";   
   mlevel = "��";
		break;
  case "silver" :
   mkey +="silver";
   mlevel = "��";
		break;
  case "bronze":
   mkey +="bronze";
   mlevel="ͭ";
		break;
  default:
   write("���ƻ�Աֻ�н𿨣�gold����������silver������ͭ����bronze����Ա��\n");
   return 1;
		break;
 }
 write("����"+mlevel+"����"+
  chinese_number(mterm+1)+"����������ǣ�\n"+(string)me->query("id")+"@"+INTERMUD_MUD_NAME+ " "+bicrypt(mkey)+"\n\n"); 
 return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��membership <[]|gold|silver|bronze>    

���ָ���ṩ��Ļ�Ա״�����ṩ������ƻ�����Ҫ���ַ�����


HELP
	);
	return 1;
}

