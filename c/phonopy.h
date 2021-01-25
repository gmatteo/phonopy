/* Copyright (C) 2021 Atsushi Togo */
/* All rights reserved. */

/* This file is part of phonopy. */

/* Redistribution and use in source and binary forms, with or without */
/* modification, are permitted provided that the following conditions */
/* are met: */

/* * Redistributions of source code must retain the above copyright */
/*   notice, this list of conditions and the following disclaimer. */

/* * Redistributions in binary form must reproduce the above copyright */
/*   notice, this list of conditions and the following disclaimer in */
/*   the documentation and/or other materials provided with the */
/*   distribution. */

/* * Neither the name of the phonopy project nor the names of its */
/*   contributors may be used to endorse or promote products derived */
/*   from this software without specific prior written permission. */

/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
/* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
/* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS */
/* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE */
/* COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, */
/* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; */
/* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER */
/* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT */
/* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN */
/* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE */
/* POSSIBILITY OF SUCH DAMAGE. */

#include <dynmat.h>

void phpy_transform_dynmat_to_fc(double *fc,
                                 const double *dm,
                                 PHPYCONST double (*comm_points)[3],
                                 PHPYCONST double (*shortest_vectors)[27][3],
                                 const int *multiplicities,
                                 const double *masses,
                                 const int *s2pp_map,
                                 const int *fc_index_map,
                                 const int num_patom,
                                 const int num_satom);
int phpy_get_dynamical_matrix_at_q(double *dynamical_matrix,
                                   const int num_patom,
                                   const int num_satom,
                                   const double *fc,
                                   const double q[3],
                                   PHPYCONST double (*svecs)[27][3],
                                   const int *multi,
                                   const double *mass,
                                   const int *s2p_map,
                                   const int *p2s_map,
                                   PHPYCONST double (*charge_sum)[3][3],
                                   const int with_openmp);
void phpy_get_charge_sum(double (*charge_sum)[3][3],
                         const int num_patom,
                         const double factor, /* 4pi/V*unit-conv and denominator */
                         const double q_cart[3],
                         PHPYCONST double (*born)[3][3]);
void phpy_get_recip_dipole_dipole(double *dd, /* [natom, 3, natom, 3, (real,imag)] */
                                  const double *dd_q0, /* [natom, 3, 3, (real,imag)] */
                                  PHPYCONST double (*G_list)[3], /* [num_G, 3] */
                                  const int num_G,
                                  const int num_patom,
                                  const double q_cart[3],
                                  const double *q_direction_cart, /* must be pointer */
                                  PHPYCONST double (*born)[3][3],
                                  PHPYCONST double dielectric[3][3],
                                  PHPYCONST double (*pos)[3], /* [num_patom, 3] */
                                  const double factor, /* 4pi/V*unit-conv */
                                  const double lambda,
                                  const double tolerance);
void phpy_get_recip_dipole_dipole_q0(double *dd_q0, /* [natom, 3, 3, (real,imag)] */
                                     PHPYCONST double (*G_list)[3], /* [num_G, 3] */
                                     const int num_G,
                                     const int num_patom,
                                     PHPYCONST double (*born)[3][3],
                                     PHPYCONST double dielectric[3][3],
                                     PHPYCONST double (*pos)[3], /* [num_patom, 3] */
                                     const double lambda,
                                     const double tolerance);
void phpy_get_derivative_dynmat_at_q(double *derivative_dynmat,
                                     const int num_patom,
                                     const int num_satom,
                                     const double *fc,
                                     const double *q,
                                     const double *lattice, /* column vector */
                                     const double *r,
                                     const int *multi,
                                     const double *mass,
                                     const int *s2p_map,
                                     const int *p2s_map,
                                     const double nac_factor,
                                     const double *born,
                                     const double *dielectric,
                                     const double *q_direction);

int phpy_compute_permutation(int * rot_atom,
                             PHPYCONST double lat[3][3],
                             PHPYCONST double (*pos)[3],
                             PHPYCONST double (*rot_pos)[3],
                             const int num_pos,
                             const double symprec);
void phpy_copy_smallest_vectors(double (*shortest_vectors)[27][3],
                                int * multiplicity,
                                PHPYCONST double (*vector_lists)[27][3],
                                PHPYCONST double (*length_lists)[27],
                                const int num_lists,
                                const double symprec);
void phpy_set_smallest_vectors(double (*smallest_vectors)[27][3],
                               int *multiplicity,
                               PHPYCONST double (*pos_to)[3],
                               const int num_pos_to,
                               PHPYCONST double (*pos_from)[3],
                               const int num_pos_from,
                               PHPYCONST int (*lattice_points)[3],
                               const int num_lattice_points,
                               PHPYCONST double reduced_basis[3][3],
                               PHPYCONST int trans_mat[3][3],
                               const double symprec);
void phpy_perm_trans_symmetrize_fc(double *fc,
                                   const int nsatom,
                                   const int level);
void phpy_perm_trans_symmetrize_compact_fc(double *fc,
                                           const int p2s[],
                                           const int s2pp[],
                                           const int nsym_list[],
                                           const int perms[],
                                           const int n_satom,
                                           const int n_patom,
                                           const int level);
void phpy_set_index_permutation_symmetry_compact_fc(double * fc,
                                                    const int p2s[],
                                                    const int s2pp[],
                                                    const int nsym_list[],
                                                    const int perms[],
                                                    const int n_satom,
                                                    const int n_patom,
                                                    const int is_transpose);
