// Silencer @ FY4 workgroup. Oct.2004
#include <ansi.h>
#define MAX_EXPERTISE 100
#define MAX_MEMORIZED 3
	
string *g_ability = ({
		"strength",
		"intelligence",
		"agility",
		"composure",
		"karma",
		"constitution",
		"kee",
		"gin",
		"sen",
		"force",
		"mana",
		"atman",
		"dodge",
		"parry",
		"no_busy",
	});
string *g_ability_info = ({
		"����ֵ��ߣ���\t\t","����ֵ��ߣ���\t\t","�ٶ�ֵ��ߣ���\t\t",
		"����ֵ��ߣ���\t\t","����ֵ��ߣ���\t\t","����ֵ��ߣ���\t\t",
		"��Ѫֵ��ߣ�������\t","����ֵ��ߣ�������\t","����ֵ��ߣ�������\t",
		"����ֵ��ߣ�����\t","����ֵ��ߣ�����\t","ħ��ֵ��ߣ�����\t",
		"ֱ�����ܻ������ӣ���\t","ֱ���мܻ������ӣ���\t",
		"��ת������������0.5��\t",
	});

mapping g_ability_pot = ([
		"dodge":	2,
		"parry":	2,
		"no_busy":	3,
]);

/* ABILITY2

str/int/comp/agi/karma/con
mana/force/atman
gin/kee/sen

shaolin: con, composure, karma, kee/gin/sen 100+
lama: con, composure, karma, kee/gin/sen 100+
legend: con, composure, karma, kee/gin/sen 100+

taoist/yinshi: int, karma, agi, mana/force/atman 50+

huashan/bonze: comp, int, con, mana/force/atman 50+

officer/beggar/wolfmount/moon/knight/fugui agi, str, karma, mana/force/atman 50+

*/

mapping m_ability3 = ([
// tank
	"lama":({"karma", "composure", "constitution", "kee", "force", "dodge", "no_busy", "3_fengmo_add", "3_an_add", "3_ma_add"}),
	"legend":({"karma", "composure", "agility", "kee", "force", "dodge", "3_wuye_add", "3_luoye_add", "3_wuzhanmei_add", "3_zhongliu_add"}),
	"shaolin":({"karma", "composure", "constitution", "kee", "force", "parry", "3_yzc_add", "3_xuanji_add", "3_foguan_add", "3_weapon_add"}),

// caster
	"taoist":({"intelligence", "karma", "agility", "atman", "mana", "force", "3_bolt1_add", "3_bolt2_add", "3_heal_add", "3_guard_add"}),
	"yinshi":({"intelligence", "karma", "agility", "dodge", "parry", "force", "3_yl9x_add", "3_bcurse_add", "3_spirit_add", "3_buffup_add"}),

// healer
	"huashan":({"agility", "composure", "constitution", "atman", "force", "parry", "3_d_duration", "3_d_damage", "3_huayu_add", "3_zhaixin_add"}),
	"bonze": ({ "intelligence", "composure", "constitution", "atman", "force", "parry", "3_zhuxian_add", "3_mind_add", "3_lxyy_add", "3_void_add"}),

// dps
	"knight":({"agility", "strength", "karma", "dodge", "parry", "force", "3_xiumu_add", "3_canyunbi_add", "3_longlife_add", "3_beisusan_add"}),
	"fugui": ({"agility", "strength", "karma", "dodge", "parry", "force", "3_erchuan_add", "3_cunjin_add", "3_lxgd_add", "3_xyxx_add"}),
	"wolfmount":({"agility", "strength", "karma", "dodge", "parry", "force", "3_wolf_add", "3_blyj_add", "3_shigu_add", "3_shexin_add"}),
	"beggar":({"agility", "strength", "karma", "dodge", "parry", "force", "3_gwxd_add", "3_pizi_add", "3_zjbl_dmg", "3_zjbl_brk"}),
	"official":({"agility", "strength", "karma", "dodge", "parry", "force", "3_zhtx_add", "3_array_add", "3_huwei_lvl", "3_huwei_pfm"}),
	"shenshui":({"agility", "strength", "karma", "dodge", "parry", "force", "3_huaxue_add", "3_slcx_add", "3_mihun_add", "3_polu_add"}),
	"moon":({"agility", "composure", "karma", "dodge", "parry", "force", "3_shnj_add", "3_thyx_add", "3_ltsc_add", "3_myqh_add"}),
	]);
	
mapping m_ability3_info = ([
	"lama": ({
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"��Ѫֵ��ߣ�������\t",
			"����ֵ��ߣ�����\t",
			"ֱ�����ܻ������ӣ�������",
			"��ת�����������ӣ���\t",
			"����ħ���ļ�����٣�����",
			"������ɱ�����ӱ����ʣ�����",
			"������Ƽӱ����ʣ�����",
		}),

	"legend": ({
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"�ٶ�ֵ��ߣ���\t\t",
			"��Ѫֵ��ߣ�������\t",
			"����ֵ��ߣ�����\t",
			"ֱ�����ܻ������ӣ�������",
			"����Ҷ�����ף���\t",
			"��Ҷ���ʧ�ܲ��ܹ�����������",
			"����չ÷���ٴ�ʹ��ʱ�䣭����",
			"���������ڼ乥����������",
		}),

	"shaolin": ({
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"��Ѫֵ��ߣ�������\t",
			"����ֵ��ߣ�����\t",
			"ֱ���мܻ������ӣ�������",
			"һָ���˺������ʣ�����",
			"����������Чʱ�����ӣ���",
			"��������ա���Чʱ�����ӣ���",
			"ǹ���������˺������ӣ���",
		}),

	"taoist": ({
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"�ٶ�ֵ��ߣ���\t\t",
			"ħ��ֵ��ߣ�����\t",
			"����ֵ��ߣ�����\t",
			"����ֵ��ߣ�����\t",
			"��ڤ��������ɱ����������",
			"���ȼ������ɱ����������",
			"������Ϣ���������ޣ�����",
			"����ֿ���Ѫ�˺�����\t��",
		}),

	"yinshi": ({
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"�ٶ�ֵ��ߣ���\t\t",
			"ֱ�����ܻ������ӣ�������",
			"ֱ���мܻ������ӣ�������",
			"����ֵ��ߣ�����\t",
			"����������æ�ң�����\t",
			"Ѫ������ʱ��ӱ���������",
			"���鹥��ʱ�˺���������\t",
			"���ľ����Ӿ����񣱣�����",
		}),

	"huashan": ({
			"�ٶ�ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"ħ��ֵ��ߣ�����\t",
			"����ֵ��ߣ�����\t",
			"ֱ���мܻ������ӣ�������",
			"�輼ʱ���ӳ�����\t",
			"�輼���Ӹ����˺�����\t",
			"+�����������컨��ӱ�\t",
			"ժ�����ӣ���������Ѫ�˺�\t",
		}),

	"bonze": ({
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"ħ��ֵ��ߣ�����\t",
			"����ֵ��ߣ�����\t",
			"ֱ���мܻ������ӣ�������",
			"���ɾ��˺������ӣ���\t",
			"��ʶ�˺�ת����������������",
			"������Ұ���⹥��������\t",
			"��ʶ���͹��������ܣ���\t",
		}),

	"moon": ({
			"�ٶ�ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"ֱ�����ܻ������ӣ�������",
			"ֱ���мܻ������ӣ�������",
			"����ֵ��ߣ�����\t",
			"˪�������ٴ�ʹ��ʱ�䣭������",
			"���һ�ߺ��Զ����мܣ�������",
			"����˥�ݼ��ٶ��������Ч������",
			"���£�����˺���������\t",
	}),

	"shenshui": ({
			"�ٶ�ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"ֱ�����ܻ������ӣ�������",
			"ֱ���мܻ������ӣ�������",
			"����ֵ��ߣ�����\t",
			"��Ѫ���ٴ�ʹ��ʱ����٣�����",
			"˪���ϼ�ڶ������ʣ�����",
			"���Ի������˺������ӣ�����",
			"����­���ڶ���ɱ�������ӣ�����",
		}),

	"official": ({
			"�ٶ�ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"ֱ�����ܻ������ӣ�������",
			"ֱ���мܻ������ӣ�������",
			"����ֵ��ߣ�����\t",
			"�ݺ����£����������٣���æ��",
			"�󷨱任������٣�������",
			"������ߣ����ȼ�\t",
			"�������ӣ�������ʹ���ؼ�",
		}),

	"beggar": ({
			"�ٶ�ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"ֱ�����ܻ������ӣ�������",
			"ֱ���мܻ������ӣ�������",
			"����ֵ��ߣ�����\t",
			"��β�������⹥����ɱ�ˣ�����",
			"�����������������ӣ���������",
			"�𾪰����˺�����ߣ���\t",
			"�𾪰���������ʲ����ж�",
		}),

	"wolfmount": ({
			"�ٶ�ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"ֱ�����ܻ������ӣ�������",
			"ֱ���мܻ������ӣ�������",
			"����ֵ��ߣ�����\t",
			"Х�����Ǿ��������ӣ���\t",
			"����һ�����������ʲ����ж�",
			"���ȹǡ��˺�����ߣ���\t",
			"�������䡻��Чʱ������2��",
		}),

	"knight": ({ 
			"�ٶ�ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"ֱ�����ܻ������ӣ�������",
			"ֱ���мܻ������ӣ�������",
			"����ֵ��ߣ�����\t",
			"��ľ���������˺����ӣ���",
			"���Ʊ̱����������ӣ���\t",
			"��������ͨ�����������ӣ���",
			"����ɢЧ�����ӣ���\t",
			}),

	"fugui": ({
			"�ٶ�ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"����ֵ��ߣ���\t\t",
			"ֱ�����ܻ������ӣ�������",
			"ֱ���мܻ������ӣ�������",
			"����ֵ��ߣ�����\t",
			"�������ڡ�˫��Ч����������",
			"�����������ʱ�����ӣ���",
			"����Ѫ�ε����������ʣ�����",
			"Ѫ������˫��Ч����������",
		}),
	]);

mapping m_ability = ([
		"knight":({"poison_dmg", "poison_dur", "chunquye_amt", "resist_gin", "resist_sen"}),
		"taoist":({"nether_add", "feeble_add", "shangjun_add", "tianshi_add", "jisi_add"}),
		"lama":({"fuhu_add", "xianglong_add", "guanyin1_add", "guanyin2_add", "mz_add"}),
		"legend": ({"wuye_add", "jushen_add", "juli_add", "juxue_add", "parry_add"}),
		"huashan": ({"huayu_add", "huashang_add", "zhaixin_add", "heal_add", "xyqj_add"}),
		"fugui": ({"jswk_add", "erchuan_add", "lgss_add", "jybt_add", "plsg_add"}),
		"shaolin": ({"sanzang_add", "foguang_add", "qixing_add", "xuanfeng_add", "hefeng_add"}),
		"yinshi": ({"thunderwhip_add", "blood_add", "buffup_add", "yljx_add", "heal_add"}),
		"wolfmount": ({"xiao_add", "shigu_add", "paragon_add", "bolang1_add", "bolang2_add"}),
		"bonze": ({"avatar_add", "lightsense_add", "void_add", "heal1_add", "heal2_add"}),
		"beggar": ({"hunyuan_add", "pizi_add", "shuhu_add", "xianglong_add", "gouwei_add"}),
		"official": ({"shi_add", "jiu_add", "ba_add", "yi_add", "huwei_add" }),
		"shenshui": ({"jiasi_add", "wwdz_add", "wwdz2_add", "huaxue_add", "yrcy_add"}),
		"moon": ({"chillblade_add", "wfbh_add", "ylkm_add", "yzhs_add", "flfy_add",}),
	]);

mapping m_ability_info = ([
	"moon": ({
			"����Ʒѩ������ϵ������\t",
			"�޷���ó���ʱ�����ӣ���",
			"���������ʱ�����ӣ���\t",
			"���ǰ��µĹ�Ч���ӣ���\t",
			"��©���̣����������Զ����м�",
		}),

	"shenshui": ({
			"�������ٴ�ʹ��ʱ����٣�����",
			"Ψ�Ҷ����ٴ�ʹ��ʱ����٣�����",
			"Ψ�Ҷ�����˺�����ߣ�����",
			"��߻�Ѫ�񹦵Ĺ�Ч������",
			"��Ⱦ�����ٴ�ʹ��ʱ����٣�����",
		}),

	"lama": ({
			"ʹ�÷����ļ�����٣�����",
			"ʹ�ý����ļ�����٣�����",
			"��������ɱ�������ӣ�����",
			"���ء���ɱ�������ӣ�����",
			"ʹ��������ļ�����٣�����",
		}),

	"official": ({
			"ʮ���������Чʱ�����ӣ�����",
			"�����ǌm�ٴ�ʹ��ʱ����٣�����",
			"���Խ����ٴ�ʹ��ʱ����٣�����",
			"һ�ֳ����ٴ�ʹ��ʱ����٣�����",
			"��������Ѫֵ��ߣ�����\t",
		}),

	"beggar": ({
			"����Ԫ�E����Ч���ӣ�����",
			"�����־����������ӣ���������",
			"��ٿ���E��ʱ�������٣�����",
			"�������޻ڡ�����ʱ����٣���",
			"����β��������Ч�������ӣ�����",
		}),

	"wolfmount": ({
			"�����ǡ���ʱ�������٣���",
			"���ȹǡ��Ĺ�Ч���ӣ�����",
			"�����Ǿ����Ĺ�Ч���ӣ�����",
			"��������ɱ��ɱ�˼ӱ����ʣ�����",
			"��������ɱ����ɱ��ɱ����������",
		}),

	"knight": ({
			"���Ʊ��������˺�����ߣ�����",
			"���Ʊ̵ĳ���ʱ���ӳ�������",
			"��ȥҲ�ָ��������ӣ���/t",
			"��ľ�������������˺����ӣ���",
			"�������������������٣���æ��",
		}),

	"taoist": ({
			"��ڤȼ��ɱ�����ӱ����ʣ�����",
			"��������ɱ�����ӱ����ʣ�����",
			"�Ͼ��ľ���ȼ���ߣ�����",
			"��ʦ�ľ���ȼ���ߣ�����",
			"�޳��ľ���ȼ���ߣ�����",
		}),

	"legend": ({
			"��Ҷ�����Ѫ�����ӣ�������",
			"ʹ�þ�����ļ�����٣�����",
			"ʹ�þ������ļ�����٣�����",
			"ʹ�þ�Ѫ���ļ�����٣�����",
			"�����ϻ����мܼ������ӣ�����",
		}),

	"huashan": ({
			"+��.�����������컨��ӱ�",
			"��˪������Ч�����ӣ�����",
			"ժ��ʽ�ٴ�ʹ��ʱ����٣�����",
			"+�������������ؼ����ķ�����",
			"����ǧ�����˼��٣���\t",
		}),

	"fugui": ({
			"��ʯΪ���Ĺ�Ч���ӣ�����",
			"�����ڵ�ʹ�ü�����٣�����",
			"�����ʯ�ٴ�ʹ��ʱ����٣���",
			"��ӥ���ó���ʱ���ӳ�����",
			"��������ٴ�ʹ��ʱ����٣�����",
		}),

	"shaolin": ({
			"ʹ�����ؾ���ظ�����������",
			"��������ٴ�ʹ��ʱ����٣�����",
			"���Ƕ����ٴ�ʹ��ʱ����٣���",
			"����ն�ٴ�ʹ��ʱ����٣���",
			"�ͷ��ٴ�ʹ��ʱ����٣�����",
		}),

	"yinshi": ({
			"���ױ޷�ɱ������ߣ�����",
			"���Ѫ����ɱ����������\t",
			"��ߺ��ľ��ļ�Ѫ��Ч������",
			"����������ֵ�ɱ����������",
			"���Ǭ���������ƹ�Ч������",
		}),

	"bonze": ({
			"���¹���������ԣ���\t",
			"��ʶɱ�������ӣ�����\t",
			"��ʶ����ʱ���ӳ�����\t",
			"���˻ָ���Ѫֵ������\t",
			"���ˣ��������ʻָ��ӱ�\t",
		}),
	]);

mapping pfm_r1_data = ([
	"tiandirenmojue": ([ // ��˷��������ƣ�enable 500 vs enable 550
		"e_id":	"tiandirenmo",
		"c_id":	"�����ħ",
		"owner":	"master figure",
		"answer":	"$N��ɴ�µ�˫�ۺ�Ȼ����տ����$N˵���㾹��Ѱ�������̲���������㡣\n",
		"fixed_atk":	530,	// Enable = 500
		"fixed_dmg":	710,	// str = 95
		"self_busy":	3,
		"cdt":			300,	// individual_cdt
		"g_cdt":		60,		// global_cdt
		"weapon":		1,
		]),

	"jichulianhuanjue": ([ // 3%*8
		"e_id":	"jichulianhuan",
		"c_id":	"�Ƴ�����",
		"owner":	"xie zhanggui",
		"answer":	"$N��ɫ΢΢һ�䣬Ц��Ц˵����ɽׯ�������ղش˱�֮�أ���л��λ��ʿ��\n",
		"fixed_atk":	500,	// Enable = 500
		"fixed_dmg":	710,	// str = 70
		"self_busy":	3,
		"cdt":			300,	// individual_cdt
		"g_cdt":		60,		// global_cdt
		"weapon":		1,
		]),

	"tianwaifeixianjue": ([
		"e_id":	"tianwanfeixian",
		"c_id":	"�������",
		"owner":	"master ye",
		"answer":	"$N΢���ף���Ц�����������յõǴ󱦣��굱Ҳ��һ�ݹ��͡�\n",
		"fixed_atk":	500,
		"fixed_dmg":	710,
		"self_busy":	3,
		"cdt":			300,
		"g_cdt":		60,
		"weapon":		1,
		]),

	"luorijue": ([
		"e_id":	"luori",
		"c_id":	"��������",
		"owner":	"master chu",
		"answer":	"$N��̾��������Ӣ�۶��į����һ�����ڵʹ�ʱ���������ߴ��ߡ�\n",
		"fixed_atk":	550,
		"fixed_dmg":	910,
		"self_busy":	2,
		"cdt":			300,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"hantianjue": ([
		"e_id":	"hantian",
		"c_id":	"��������",
		"owner":	"master ximen",
		"answer":	"$N���������˵�����Ȿ����ˣ�һ���������ˣ��ҵ�Ҫ���Կ���\n",
		"fixed_atk":	700,
		"fixed_dmg":	1500,
		"self_busy":	1,
		"cdt":			300,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"miwujue": ([
		"e_id":	"miwu",
		"c_id":	"ʮ������",
		"owner":	"master li",
		"answer":	"$N�˸߲��ҵ�˵����û�뵽�Ҿ��ô˱�������������֮�ң�����֮����\n",
		"fixed_atk":	500,
		"fixed_dmg":	1000,
		"self_busy":	1,
		"cdt":			180,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"soulflamejue": ([
		"e_id":	"soulflame",
		"c_id":	"ħ������",
		"owner":	"yi ku",
		"answer":	"$Nϲ�������������ⱦ���������°����Ǹ�����Ƭ��\n",
		"fixed_atk":	800,
		"fixed_dmg":	1000,
		"self_busy":	2,
		"cdt":			180,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"jixingjue": ([
		"e_id":	"jixing",
		"c_id":	"���»���",
		"owner":	"master shi",
		"answer":	"$Nϲ�������ⱦ�������䵱�����Ȼ����һ��¥��\n",
		"fixed_atk":	500,
		"fixed_dmg":	1000,
		"self_busy":	0,
		"cdt":			180,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"jiemaijue": ([
		"e_id":	"jiemai",
		"c_id":	"��Ѫ����",
		"owner":	"wan chunliu",
		"answer":	"$NЦ��������м������ҵ�ҽ�����»��������Ķࡣ\n",
		"fixed_atk":	500,
		"fixed_dmg":	1000,
		"self_busy":	1,
		"cdt":			300,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"mengyanjue": ([
		"e_id":	"mengyan",
		"c_id":	"�����ٻ�",
		"owner":	"master ding",
		"answer":	"$N��ͷ������˵�˷ǵ����������������¡�\n",
		"fixed_atk":	500,
		"fixed_dmg":	1000,
		"self_busy":	1,
		"cdt":			300,
		"g_cdt":		60,
		"weapon":		0,
		]),
	]);

int deduct_ability_cost(object ob, string arg, int flag);
int check_ability(object me,string arg, int flag);
int improve_ability(object me,string arg, int flag);
int check_ability_improve(object me, string arg, int flag);
string get_ability_idf(object me,string arg, int flag);
string get_ability_info(object ob, string arg, int flag);

// L80-120.ÿ10�����Զ�ѧ���㣬���������120����ѧ��һ���̣���
int check_ability_improve(object me, string arg, int flag)
{
	int level, a_lvl;
	level = F_LEVEL->get_level(me->query("combat_exp"));
	a_lvl = check_ability(me, arg, flag);
	if( a_lvl >= 10 ) {
		return 0;
	}
	if( flag == 0 && level < 80 ) {
		return 0;
	}
	if( flag == 1 && level < 100 ) {
		return 0;
	}
	if( flag == 3 ) {
		if( level < 40 ) {
			return 0;
		}
		if( (level-40)/10 + 1 > a_lvl ) {
			return 1;
		} else {
			return 0;
		}
	}
	if( (level-80)/5 + 1 > a_lvl ) {
		return 1;
	}
	return 0;
}

varargs int check_ability(object me,string arg, int flag)
{
	int level, result;
	
	// Although we have defined NPC ability here, 
	// what really matter are only dodge/parry/menpai abilities, 
	// att are useless since we don't actually add them to NPC
	if( !userp(me) && !me->query("possessed") ) {
		if( flag == 3 ) {
			// disable NPC ability3
			return 0;
		} else {
			level = F_LEVEL->get_level(me->query("combat_exp"));
			if( level < 80 ) {
				return 0;
			}
			if( level > 150) {
				return 14;
			}
			return (level-80)/5;
		}
	}
	
	if( flag == 3) {
		// Ability3 TASK		
		result = me->query("ability3/"+ me->query("class")+ "/"+ arg);
	} else {
		// Ability ����
		result = me->query("ability2/"+ me->query("class")+ "/"+ arg) + me->query("ability/"+arg);
	}
	return result;
}

int check_ability_cost(object me, string arg, int flag) 
{
	int cost;

	if( flag == 1 ) {
		cost = 2;
	} else if( flag == 3 ) {
		cost = 1;
	} else {
		if( member_array(arg, g_ability) == -1 ) {
			return 0;
		}
		cost = g_ability_pot[arg];
		if( !cost ) {
			cost = 1;
		}
	}
	return cost;
}


// ÿ�κķ�һ��������
int deduct_ability_cost(object me, string arg, int flag)
{
	int lvl, cost;
	int n;
	int total_count, saved_book, saved_task, saved_count, saved_ability3, learned_ability3;
	lvl = check_ability(me, arg, flag);
	cost = check_ability_cost(me, arg, flag);
	
	if (flag == 1 || flag == 0) {
		if( cost > me->query("saved_quest")/60/100 - me->query("learned_ability") ) {
			return 0;
		}
		me->add("learned_ability", cost);
	}
	
	if( flag == 3 ) {
		n = 300;
		total_count = me->query("TASK");
		saved_book = me->query("marks/book_task");
		saved_task = total_count - saved_book;
		saved_count = saved_task + saved_book/2;
		saved_ability3 = saved_count/n;
		learned_ability3 = me->query("learned_ability3");
		if( cost > saved_ability3 - learned_ability3 ) {
			return 0;
		}
		me->add("learned_ability3", cost);
	}
	
	return 1;
}

int improve_ability(object me,string arg, int flag)
{
	int lv;
	string myclass;

	myclass = me->query("class");
	if( !flag ) {
		me->add("ability/"+arg,1);
		switch (arg) {
			case "strength":
				{
					me->add("str",1);
					break;
				}
			case "intelligence":
				{
					me->add("int",1);
					break;
				}
			case "composure":
				{
					me->add("cps",1);
					break;
				}
			case "karma":
				{
					me->add("kar",1);
					break;
				}
			case "agility":
				{
					me->add("agi",1);
					break;
				}
			case "constitution":
				{
					me->add("con",1);
					break;
				}
			case "mana":
				{
					me->add("Add_mana/ability",50);
					me->add("max_mana",50);
					break;
				}
			case "atman":
				{
					me->add("Add_atman/ability",50);
					me->add("max_atman",50);
					break;
				}
			case "force":
				{
					me->add("Add_force/ability",50); 
					me->add("max_force",50);
					break;
				}
			case "kee":
				{
					me->add("max_kee",100);
					break;
				}
			case "gin":
				{
					me->add("max_gin",100);
					break;
				}
			case "sen":
				{
					me->add("max_sen",100);
					break;
				}
			case "parry": // in combatd.c
			case "dodge": // in combatd.c
			case "no_busy": // in action.c
				{
					break;
				}
		}
	} else if( flag == 1 ) {
		me->add("ability2/"+myclass+"/"+arg,1);
	} else if( flag == 3 ) {
		me->add("ability3/"+ myclass + "/" + arg,1);
		switch (arg) {
			case "strength":
				{
					me->add("str",1);
					break;
				}
			case "intelligence":
				{
					me->add("int",1);
					break;
				}
			case "composure":
				{
					me->add("cps",1);
					break;
				}
			case "karma":
				{
					me->add("kar",1);
					break;
				}
			case "agility":
				{
					me->add("agi",1);
					break;
				}
			case "constitution":
				{
					me->add("con",1);
					break;
				}
			case "mana":
				{
					me->add("Add_mana_only/ability3",50);	
					me->add("max_mana",50);
					break;
				}
			case "atman":
				{
					me->add("Add_atman_only/ability3",50);
					me->add("max_atman",50);
					break;
				}
			case "force":
				{
					me->add("Add_force_only/ability3",50); 
					me->add("max_force",50);
					break;
				}
			case "kee":
				{
					me->add("max_kee",100);
					break;
				}
			case "gin":
				{
					me->add("max_gin",100);
					break;
				}
			case "sen":
				{
					me->add("max_sen",100);
					break;
				}
			case "parry": // in combatd.c
			case "dodge": // in combatd.c
			case "no_busy": // in action.c
				{
					break;
				}
		}
	}
	return 1;
}

string get_ability_info(object ob, string arg, int flag)
{
	int lv, cost, n;
	string desc, msg, myclass;

	lv = check_ability(ob, arg, flag);
	cost = check_ability_cost(ob, arg, flag);
	desc = get_ability_idf(ob,arg,flag);
	if( flag == 1 ) {
		// ability's ���ɼ���
		myclass = ob->query("class");
		if( arrayp(m_ability[myclass]) ) {
			n = member_array(arg,m_ability[myclass]);
			if( n != -1 ) {
				msg = m_ability_info[myclass][n];
				msg = sprintf(msg+"\t%-10s\t%3d\n",desc, cost);
				return msg;
			}
		}
		return "";
	}
	if( flag == 3) {
		// ability3
		myclass = ob->query("class");
		if( arrayp(m_ability3[myclass]) ) {
			n = member_array(arg,m_ability3[myclass]);
			if( n != -1 ) {
				msg = m_ability3_info[myclass][n];
				msg = sprintf(msg+"\t%-10s\t%3d\n",desc, cost);
				return msg;
			}
		}
		return "";
	}
	n = member_array(arg, g_ability);
	if( n != -1 ) {
		msg = g_ability_info[n];
		msg = sprintf(msg+"\t%-10s\t%3d\n", desc, cost);
		return msg;
	}
	return "";
}


string get_ability_idf(object me,string arg, int flag)
{
	int lev = check_ability(me,arg,flag);
	// 1,2,3,4 Basic
	// 5,6,7 Advanced
	// 8,9: Master
	// 10: Grand Master
	string *tough_level_desc = ({
		YEL "һ����֪" NOR,//0
		HIB "�����ž�" NOR,//1
		HIB "��֪һ��" NOR,//2
		HIB "��ͨƤë" NOR,//3
		HIB "������" NOR,//4
		CYN "��Ȼ���" NOR,//5
		CYN "�������" NOR,//6
		CYN "�Ƿ��켫" NOR,//7
		HIC "һ����ʦ" NOR,//8
		HIC "������˫" NOR,//9
		HIW "��ɲ�" NOR,//10
		HIW "��ɲ�" NOR,//11 - These are just for some NPC setup
		HIW "��ɲ�" NOR,//12
		HIW "��ɲ�" NOR,//13
		HIW "��ɲ�" NOR,//14
		HIW "��ɲ�" NOR,//15
		HIW "��ɲ�" NOR,//16
		HIW "��ɲ�" NOR,//17
		HIW "��ɲ�" NOR,//18
		HIW "��ɲ�" NOR,//19
		HIW "��ɲ�" NOR,//20
	});
	return (tough_level_desc[lev]+"��"+ lev +"��");
}

mapping	reward_perform_1(string p_name)
{
//	CHANNEL_D->do_sys_channel("sys",sprintf("perform data returned is %O. \n", pfm_r1_data[p_name]));
	return pfm_r1_data[p_name];
}

mapping query_pfm_r1()
{
	return pfm_r1_data;
}

int check_pfm_r1(object who, string p_name)
{
	mapping perform;
	int duration, duration1,duration2;
	perform = pfm_r1_data[p_name];
	if( F_LEVEL->get_level(who->query("combat_exp")) < 100 ) {
		tell_object(who,"ʹ�÷��ƾ�����Ҫ�ȼ�100���ϡ�\n");
		return 0;
	}
	if( !who->query_weapon() && perform["weapon"] ) {
		tell_object(who,"ʹ�ô��ľ��������������\n");
		return 0;
	}
	if( who->query_weapon() && !perform["weapon"] ) {
		tell_object(who,"ʹ�ô��ľ�������֡�\n");
		return 0;
	}
	// Low level has a 30mins CDT, so it's a one short boost
	if( F_LEVEL->get_level(who->query("combat_exp")) < 100 ) {
		duration = who->query("timer/pfm/pfm_r1") + 1800 - time();
		if( duration > 0 ) {
			tell_object(who,"���������ᣬ����Ҫ�ȴ�"+(duration/60)+"���Ӳ����ٴ�ʹ�÷��ƾ�����\n");
			return 0;
		}
	}
	if( who->query("pfm_r1/"+p_name+"/expertise") < MAX_EXPERTISE && who->query("pfm_r1/"+p_name+"/memorized") < 1 ) {
		tell_object(who,"�㻹û���������ա�"+perform["c_id"]+"�����޷�����ʹ�á�\n");
		return 0;
	}
	duration1 = who->query("timer/pfm/pfm_r1") + perform["g_cdt"] - time();
	if( duration1 > 0 ) {
		tell_object(who,"�㻹Ҫ��Ҫ�ȴ�"+duration1+"�����ʹ��߳�����֮�ؼ���\n");
	}
	duration2 = who->query("timer/pfm/"+p_name) + perform["cdt"] - time();
	if( duration2 > 0 ) {
		tell_object(who,"�㻹Ҫ��Ҫ�ȴ�"+duration2+"�����ʹ�á�"+perform["c_id"]+"�ľ���\n");
	}
	if( duration1 > 0 || duration2 > 0 ) {
		return 0;
	}
	return 1;
}

int add_pfm_r1_expertise(object who, string p_name, int i)
{
	if( who->query("pfm_r1/"+p_name +"/expertise") == 24 ) {
		CHANNEL_D->do_sys_channel("info",sprintf("%s��%s���ġ�%s���ľ��Ѿ������ž��ˡ�\n", 
		who->name(1),who->query("id"),pfm_r1_data[p_name]["c_id"]));
	}
	if( who->query("pfm_r1/"+p_name +"/expertise") == 49 ) {
		CHANNEL_D->do_sys_channel("info",sprintf("%s��%s���ġ�%s���ľ��Ѿ��������ˡ�\n", 
		who->name(1),who->query("id"),pfm_r1_data[p_name]["c_id"]));
	}
	if( who->query("pfm_r1/"+p_name +"/expertise") == 74 ) {
		CHANNEL_D->do_sys_channel("info",sprintf("%s��%s���ġ�%s���ľ��Ѿ���������ˡ�\n", 
		who->name(1),who->query("id"),pfm_r1_data[p_name]["c_id"]));
	}
	if( who->query("pfm_r1/"+p_name +"/expertise") == 99 ) {
		CHANNEL_D->do_sys_channel("info",sprintf("%s��%s���ġ�%s���ľ��Ѿ���ɲ��ˡ�\n", 
		who->name(1),who->query("id"),pfm_r1_data[p_name]["c_id"]));
	}
	if( who->query("pfm_r1/"+p_name+"/expertise")+i <= MAX_EXPERTISE ) {
		who->add("pfm_r1/"+p_name+"/expertise",i);
	} else {
		who->set("pfm_r1/"+p_name+"/expertise",MAX_EXPERTISE);
	}
	return 1;
}
	
int add_pfm_r1_memorized(object who, string p_name, int i)
{
	if( who->query("pfm_r1/"+p_name+"/memorized")+i <= MAX_MEMORIZED ) {
		who->add("pfm_r1/"+p_name+"/memorized",i);
	} else {
		who->set("pfm_r1/"+p_name+"/memorized",MAX_MEMORIZED);
	}
	if( who->query("pfm_r1/"+p_name+"/memorized") < 0 ) {
		who->set("pfm_r1/"+p_name+"/memorized",0);
	}
	return 1;
}

int pfm_r1_book_reward(object me, object who, object obj)
{
	int i, n, num;
	string* pfm_name;
//	CHANNEL_D->do_sys_channel("sys"," checking books\n");
	if( !obj->query("pfm_r1") ) {
		return 0;
	}
	num = sizeof(pfm_r1_data);
	pfm_name = keys(pfm_r1_data);
	n = 999;
	for( i = 0; i < num; i++) {
//		CHANNEL_D->do_sys_channel("sys", sprintf("%d master is %s\n", i, pfm_r1_data[pfm_name[i]]["owner"]));
		if( pfm_r1_data[pfm_name[i]]["owner"] == who->query("id") ) {
			n = i;
			break;
		}
	}
//	CHANNEL_D->do_sys_channel("sys"," i ="+i+"\n");
	if( n == 999 ) {
		return 0;
	}
	if( me->query("pfm_r1/"+pfm_name[i]+"/expertise")+me->query("pfm_r1/"+pfm_name[i]+"/memorized") >= MAX_EXPERTISE ) {
		tell_object(me,who->name()+"΢΢һЦ������Դ��ķ����˽��Ѿ����������ˡ�\n");
		return 0;
	}
	if( me->query("pfm_r1/"+pfm_name[i]+"/memorized") >= MAX_MEMORIZED ) {
		tell_object(me,who->name()+"ҡҡͷ˵�����������Ĵ�ҳ��\n");
		return 0;
	}
	message_vision(pfm_r1_data[pfm_name[n]]["answer"], who, me);
	tell_object(me,YEL+who->name()+"˵�����츳���ޣ�����ָ���㼸�С�\n"+who->name()+"������ߵ���˵�˼��䡣\n"NOR);
	tell_object(me,YEL"���ƺ�������һЩ��"+pfm_r1_data[pfm_name[n]]["c_id"]+"�����ľ���\n"NOR);
	add_pfm_r1_memorized(me,pfm_name[n],1);
	if( obj ) {
		destruct(obj);
	}
	return 1;
}